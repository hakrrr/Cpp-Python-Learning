# Basic
"""
for .. in ..
"""


def is_leap(y):
    leap = False
    if y % 4 == 0:
        leap = True
        if y % 100 == 0:
            leap = False
            if y % 400 == 0:
                leap = True
    return leap


year = int(input())
print(is_leap(year))
