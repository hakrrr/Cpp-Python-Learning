# yield boosts the performance
from timeit import default_timer as time


def solve(a, b):
    a += 'z'
    b += 'z'
    ptrA = ptrB = 0
    for _ in range(len(a) + len(b) - 2):
        if a[ptrA:] <= b[ptrB:]:
            yield a[ptrA]
            ptrA += 1
        else:
            yield b[ptrB]
            ptrB += 1


def solving(a, b):
    return ''.join(solve(a, b))


t = int(input())
for t_itr in range(t):
    A = input()
    B = input()
    print(solving(A, B))
