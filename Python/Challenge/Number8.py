# yield boosts the performance
from timeit import default_timer as time
'''
1
ZZYYZZZA
ZZYYZZZB

Sol: ZZYYZZYYZZZAZZZB

5
DAD
DAD
ABCBA
BCBA
BAC
BAB
DAD
DABC
YZYYZYZYY
ZYYZYZYY

Sol:
DADADD
ABBCBACBA
BABABC
DABCDAD
YZYYZYYZYZYYZYZYY
'''


def solve(a, b):
    size = len(a) + len(b)
    a += 'z'
    b += 'z'
    ptrA = ptrB = 0
    for _ in range(size):
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
