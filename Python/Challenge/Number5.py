# Dictionary & Exceptions
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


inp = input()
N = input().split(' ')
A = input().split(' ')
B = input().split(' ')
print(solve(N, A, B))
