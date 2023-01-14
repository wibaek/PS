# 210725 solved
import sys
input = sys.stdin.readline
def solution():
    n = int(input())
    numbers = [int(input()) for _ in range(n)]
    countList = [0 for _ in range(8001)] 
    print(round(sum(numbers)/n))
    print(sorted(numbers)[n//2])
    for i in numbers:
        countList[4000+i] += 1
    largest = max(countList)
    largestList = []
    for i in range(8001):
        if countList[i] == largest:
            largestList.append(i)
    if len(largestList) == 1:
        print(largestList[0] - 4000)
    else:
        print(largestList[1] - 4000)
    print(max(numbers)-min(numbers))
solution()