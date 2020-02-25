# All substrings from string using itertools.combinations & globals
from itertools import combinations

'''
itertools functions return itertools objects (yield)
Notes on combinations
combinations(iterable, r) generates r length subsequences (not unique in value) from iterable
combinations(range(4), 2) --> 01 02 03 12 13 23
combinations('ABCD', 2) --> AB AC AD BC BD CD
'''
# globals
Kevin = Stuart = 0


def substrings(s):
    return [s[x:y] for x, y in combinations(range(len(s)+1), 2)]


def minion_game(s):
    global Kevin, Stuart
    for i in range(len(s)):
        comb = len(s) - i
        if s[i] in 'AEIOU':
            Kevin += comb
        else:
            Stuart += comb


# main
print(substrings('BANANA'))
minion_game('BANANA')
print('Kevin ' + str(Kevin) if Kevin > Stuart else 'Stuart ' + str(Stuart) if Stuart > Kevin else "Draw")
