# 210801 solved
import heapq
import sys
input = sys.stdin.readline

def solution():
    n = int(input())
    heap=[]
    for _ in range(n):
        i = int(input())
        if i==0 and len(heap)==0:
            print(0)
        elif i==0:
            print(heapq.heappop(heap))
        else:
            heapq.heappush(heap,i)
solution()