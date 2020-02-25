# Dictionary, Exceptions & Map
from itertools import product


def solve(n, a, b):
    d = {}
    res = 0
    for x in a:
        d[int(x)] = 1
    for x in b:
        d[int(x)] = -1
    for i in n:
        try:
            res += d[int(i)]
        except (ValueError, KeyError):
            pass
    return res


def solve():
    k, m = map(int, input().split())
    n = list(list(map(int, input().split()[1:])) for _ in range(k))
    n = list(map(lambda i: sum(x**2 for x in i) % m, product(*n)))
    print(max(n))


solve()
inp = input()
N = input().split(' ')
A = input().split(' ')
B = input().split(' ')
print(solve(N, A, B))
