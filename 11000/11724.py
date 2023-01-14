import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def solution():
    N, M = map(int,input().split())
    
    isConnected = [[False for _ in range(N+1)] for _ in range(N+1)]
    for i in range(M):
        get = list(map(int,input().split()))
        get.sort()
        isConnected[get[0]][get[1]] = True
        isConnected[get[1]][get[0]] = True
    
    isVisited = [False for _ in range(N+1)]
    
    answer = 0
    for i in range(1, N+1):
        answer += check(i, isConnected, isVisited, N)
    print(answer)
    
def check(point, isConnected, isVisited, N):
    if isVisited[point]:
        return 0
    isVisited[point] = True
    for i in range(1, N+1):
        if isConnected[point][i]:
            check(i, isConnected, isVisited, N)
    return 1
    
solution()