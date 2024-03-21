# 2239 스도쿠
# 2024 - 03 - 21
def rec(n, board):
    x, y = n // 9, n % 9
    if n == 81:
        for row in board:
            print("".join(map(str, row)))
        exit()

    if board[x][y] != 0:
        rec(n + 1, board)
        return

    available = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    for i in range(9):
        if board[x][i] in available:
            available.remove(board[x][i])
        if board[i][y] in available:
            available.remove(board[i][y])
    zone_x, zone_y = x // 3, y // 3
    for i in range(zone_x * 3, zone_x * 3 + 3):
        for j in range(zone_y * 3, zone_y * 3 + 3):
            if board[i][j] in available:
                available.remove(board[i][j])

    for num in available:
        board[x][y] = num
        rec(n + 1, board)
        board[x][y] = 0


board = []
for _ in range(9):
    row = list(map(int, list(input())))
    board.append(row)

rec(0, board)
