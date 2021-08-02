# 210724 solved
def isCursed(n):
    if "666" in str(n):
        return True
    return False

def solution():
    n = int(input())
    cursedList = []
    i = 0
    current = 666
    while(i < 10000):
        if isCursed(current):
            i += 1
            cursedList.append(current)
        current += 1
    print(cursedList[n-1])
    
solution()