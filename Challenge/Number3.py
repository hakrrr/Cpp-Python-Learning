# itertools
from itertools import product

"""
Notes on generators:
myGen = (i for i in range(4)), which is generator can only be iterated once
A function can also work like a generator by using the key term 'yield'
It saves the progress of a function's (suspended state) till the next call
Basically:
def f123():
    # code
    yield 1
    yield 2
    yield 3

for item in f123():
    print item
"""


def yd():
    print('first')
    yield 1
    yield 2
    yield 3


for i in yd():
    print(i)
