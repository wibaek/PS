from collections import deque

def solution():
    M, N = map(int, input().split())
    box = [list(map(int, input().split())) for _ in range(N)]
   
    order = deque()
  # 초기상태의 토마토
    for i in range(N):
        for j in range(M):
            if box[i][j] == 1:
                order.append((i, j ,0))
    while(order):
        y, x, day = order.pop()
    
        dx = [0, 0, 1, -1]
        dy = [1, -1, 0, 0]
    
        for t in range(4):
            nx = x + dx[t]
            ny = y + dy[t]
            if 0 <= nx < M and 0 <= ny < N:
                if box[ny][nx] == 0:
                    order.appendleft(ny, nx, day + 1)
                    box[ny][nx] = 1
  
    for row in box:
        if 0 in row:
            return -1
    return day
  
print(solution())