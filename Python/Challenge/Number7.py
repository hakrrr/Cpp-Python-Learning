# pos & neg lookbehind
import re
rs = r'\w((!|@|#|\$|%|&| )+)(?=\w)'
n, m = map(int, input().rstrip().split())
matrix = [''] * n * m
for x in range(n):
    inp = input()
    for y in range(m):
        matrix[y*n + x] = inp[y]

matrix = ''.join(map(str, matrix))
matrix = re.sub(rs, lambda s: s.group(0)[0] + ' ' * len(s.group(1)), matrix)
print(matrix)
