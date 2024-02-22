# 210724 solved
def isAnswer(largest, kList, n):
    count = 0
    for i in kList:
        count += i // largest
    if count >= n:
        return True
    else:
        return False

def solution():
    k, n = map(int, input().split())
    kList = []
    for i in range(k):
        kList.append(int(input()))
    kTotal = 0
    for i in kList:
        kTotal += i
    largest = (kTotal // n) + 1
    start, mid, end = 0, largest // 2, largest
    while(True):
        first = isAnswer(mid, kList, n)
        second = isAnswer(mid+1, kList, n)
        if first and not second:
            print(mid)
            break
        elif first and second:
            start = mid
            mid = (start + end) // 2
        else:
            end = mid
            mid = (start + end) // 2
                 


solution()