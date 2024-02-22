import sys
input = sys.stdin.readline
import heapq

def solution():
    k = int(input())
    minHeap = []
    maxHeap = []
    visited = [False for i in range(k)]
    for i in range(k):
        get = list(input().split())
        if get[0] == 'I':
            heapq.heappush(minHeap, (int(get[1]), i))
            heapq.heappush(maxHeap, (-int(get[1]), i))
            visited[i] = True
        elif get[1] == '1':
            while maxHeap and not visited[maxHeap[0][1]]:
                heapq.heappop(maxHeap)
            if maxHeap:
                visited[maxHeap[0][1]] = False
                heapq.heappop(maxHeap)
        else:
            while minHeap and not visited[minHeap[0][1]]:
                heapq.heappop(minHeap)
            if minHeap:
                visited[minHeap[0][1]] = False
                heapq.heappop(minHeap)
                
    while maxHeap and not visited[maxHeap[0][1]]:
        heapq.heappop(maxHeap)
    while minHeap and not visited[minHeap[0][1]]:
        heapq.heappop(minHeap)
    if maxHeap and minHeap:    
        print(-maxHeap[0][0], minHeap[0][0])
    else:
        print("EMPTY")
for _ in range(int(input())):
    solution()