import sys
input = sys.stdin.readline
import heapq

def solution():
    V, E = map(int, input().split())
    K = int(input()) # Start node
    heap = []
    dist = [987654321 for _ in range(V+1)]
    dijkstra = [[] for _ in range(V + 1)]
    for i in range(E):
        u, v, w = map(int, input().split())
        dijkstra[u].append((v, w))
    
    heapq.heappush(heap, (0, K))
    while(heap):
        cost, node = heapq.heappop(heap)
        if dist[node] < cost:
            continue
        dist[node] = cost
        for nextNode, nextCost in dijkstra[node]:
            if dist[nextNode] > cost + nextCost:
                dist[nextNode] = cost + nextCost
                heapq.heappush(heap, (cost + nextCost, nextNode))                

    # output
    for i in range(1, V+1):
        length = dist[i]
        if length == 987654321:
            print("INF")
        else:
            print(length)
            
solution()