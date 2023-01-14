# 210725 solved
def solution():
    n, m = map(int, input().split())
    sheets = list(map(int,input().split()))
    cur = 0
    totalPrinted = 0
    while(True):
        if isLargest(cur, sheets):
            sheets[cur] = -1
            totalPrinted += 1
            if cur == m:
                print(totalPrinted)
                return 0
        cur += 1
        if cur == n:
            cur = 0
            
def isLargest(cursor, cList):
    for i in cList:
        if i > cList[cursor]:
            return False
    return True
    
TESTCASE = int(input())
for _ in range(TESTCASE):
    solution()