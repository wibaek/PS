# 2024 - 03 - 25
n = int(input())
board = [[0 for _ in range(n)] for _ in range(n)]


def check_able_to_place(y, x):
    global board
    global n
    # check diagonal
    for i in range(n):
        if y - i >= 0 and x - i >= 0:
            if board[y - i][x - i] == 1:
                return False
        if y - i >= 0 and x + i < n:
            if board[y - i][x + i] == 1:
                return False
    return True


def rec(y):
    global answer
    global board
    global n
    global x_able
    if y == n:
        answer += 1
        return

    for i in range(n):
        if not x_able[i]:
            continue
        if check_able_to_place(y, i):
            board[y][i] = 1
            x_able[i] = False
            rec(y + 1)
            x_able[i] = True
            board[y][i] = 0


answer = 0
x_able = [True for _ in range(n)]
for i in range(n):
    board[0][i] = 1
    x_able[i] = False
    rec(1)
    x_able[i] = True
    board[0][i] = 0

print(answer)
