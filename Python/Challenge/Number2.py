# List & __getattribute__ & for

mList = list()
mLoops = int(input())
for i in range(0, mLoops):
    mInput = input().split(' ')
    if len(mInput) == 1:
        if mInput[0] == 'print':
            print(mList)
        else:
            mList.__getattribute__(mInput[0])()

    elif len(mInput) == 2:
        mList.__getattribute__(mInput[0])(int(mInput[1]))

    else:
        mList.__getattribute__((mInput[0]))(int(mInput[1]), int(mInput[2]))
