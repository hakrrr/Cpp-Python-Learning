import numpy as np
import gym
import random
import time
import torch
# @https://deeplizard.com/learn/video/HGeI30uATws

env = gym.make("FrozenLake-v0")
action_space_size = env.action_space.n
state_space_size = env.observation_space.n

q_table = np.zeros((state_space_size, action_space_size))

# limits
num_episodes = 100000
max_steps_per_episode = 100

# learning rate (alpha) & discount rate (gamma)
learning_rate = 0.1
discount_rate = 0.99

# exploration vs. exploitation balance; decaying pre episode
exploration_rate = 1
max_exploration_rate = 1
min_exploration_rate = 0.01
exploration_decay_rate = 0.001

tens = torch.tensor([1])
tens2 = torch.tensor([[[1., -1.], [1., -1.]]])
asd = torch.cat(tens, tens2)
print(torch)

# q-learning algorithm
print("***Training...***")
rewards_all_episodes = []

for episode in range(num_episodes):
    # init new episode params
    state = env.reset()

    done = False
    rewards_current_episode = 0

    for step in range(max_steps_per_episode):
        # Exploration-exploitation trade-off; ert > er -> exploit
        exploration_rate_treshold = random.uniform(0, 1)
        if exploration_rate_treshold > exploration_rate:
            action = np.argmax(q_table[state, :])
        else:
            action = env.action_space.sample()

        # Take new action
        new_state, reward, done, info = env.step(action)

        # Update Q-table
        q_table[state, action] = (1 - learning_rate) * q_table[state, action] + \
            learning_rate * (reward + discount_rate * np.max(q_table[new_state, :]))

        # Set new state + new reward
        state = new_state
        rewards_current_episode += reward

        if done:
            break

    # Update exloration rate
    exploration_rate = min_exploration_rate + (max_exploration_rate - min_exploration_rate) * \
        np.exp((-exploration_decay_rate*episode))
    rewards_all_episodes.append(rewards_current_episode)

# Calculate and print the average reward per thousand episodes
rewards_per_thousand_episodes = np.split(np.array(rewards_all_episodes), num_episodes/1000)
count = 1000
print("***Average reward per thousand episodes***\n")
for r in rewards_per_thousand_episodes:
    print(count, ": ", str(sum(r/1000)))
    count += 1000

# Print finallized q-table
print("\n\n***Q-table***\n")
print(q_table)

for episode in range(3):
    state = env.reset()
    done = False
    print("***EPISODE ", episode+1, "**\n\n\n\n")
    time.sleep(1)

    for step in range(max_steps_per_episode):
        print('\n' * 100)
        env.render()
        time.sleep(0.3)

        action = np.argmax(q_table[state, :])
        new_state, reward, done, info = env.step(action)

        if done:
            print('\n' * 100)
            env.render()
            if reward == 1:
                print("***You reached the goal***")
                time.sleep(3)
            else:
                print("***You fell through a hole!***")
                time.sleep(3)
            print('\n' * 100)
            break

        state = new_state

env.close()
