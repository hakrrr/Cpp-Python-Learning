import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
import time
# @https://www.youtube.com/watch?v=wQ8BIBpya2k

mnist = tf.keras.datasets.mnist  # 28x28 images of handwritten numbers

(x_train, y_train), (x_test, y_test) = mnist.load_data()    # x => images, y => actual numbers in int

x_train = tf.keras.utils.normalize(x_train, axis=1)
x_test = tf.keras.utils.normalize(x_test, axis=1)

model = tf.keras.models.Sequential()
model.add(tf.keras.layers.Flatten())
model.add(tf.keras.layers.Dense(128, activation=tf.nn.relu))
model.add(tf.keras.layers.Dense(128, activation=tf.nn.relu))
model.add(tf.keras.layers.Dense(128, activation=tf.nn.relu))
model.add(tf.keras.layers.Dense(10, activation=tf.nn.softmax))
# softmax is a probability distr. meaning the sum of the output nodes are equal 1
# sigmoid isn't

# opt => e.g. Stochastic Gradient Descent, loss => mean sqaured error
model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])

print('Starting to train...')
time.sleep(1)
model.fit(x_train, y_train, epochs=3)

print('\n' * 10)
print('Evaluating...')
time.sleep(1)
val_loss, val_acc = model.evaluate(x_test, y_test)
print('Loss: ', val_loss, 'Accuracy: ', val_acc)

model.save('num_reader.model')
n_model = tf.keras.models.load_model('num_reader.model')


predictions = n_model.predict(x_test)
# Note: output will be a tensor with probability distribution, therefore use numpy
print('Result of predictions: ')


# Show results on predictions
for i in range(len(predictions)):
    print('Predicted Number: ', np.argmax(predictions[i]))
    plt.title('Input: Handwritten digit')
    plt.imshow(x_test[i], cmap=plt.cm.binary)
    plt.show()

