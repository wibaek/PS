# 2024 - 04 - 30
n = int(input())
board = [[0] * n for _ in range(n)]

for i in range(n):
    inp = input()
    for j in range(n):
        value = inp[j]
        if value == "W":
            board[i][j] = 2
        elif value == "B":
            board[i][j] = 1


def maxReverse(board, x, y):
    count = 0
    dx = [-1, -1, -1, 0, 0, 1, 1, 1]
    dy = [-1, 0, 1, -1, 1, -1, 0, 1]
    for i in range(8):
        count += checkLine(board, x, y, dx[i], dy[i])
    return count


def checkLine(board, x, y, dx, dy):
    n = len(board)
    count = 0
    x += dx
    y += dy
    while 0 <= x < n and 0 <= y < n:
        if board[x][y] == 2:
            count += 1
        elif board[x][y] == 1:
            return count
        elif board[x][y] == 0:
            return 0
        x += dx
        y += dy
    return 0


maxCount = 0
maxX = -1
maxY = -1
for i in range(n):
    for j in range(n):
        if board[i][j] == 0:
            count = maxReverse(board, i, j)
            if count > maxCount:
                maxCount = count
                maxX = i
                maxY = j

if maxCount == 0:
    print("PASS")
else:
    print(maxY, maxX)
    print(maxCount)
