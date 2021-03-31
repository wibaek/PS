import sys
input = sys.stdin.readline


def solution():
    dictRange, caseRange = map(int, input().split())
    pocketDict = {}
    for i in range(dictRange):
        pocketDict[str(i + 1)] = input().strip()
    pocketDictReverse = {j: i for i, j in pocketDict.items()}

    for i in range(caseRange):
        get = input().strip()
        if get.isdigit():
            print(pocketDict[get])
        else:
            print(pocketDictReverse[get])


solution()
