import sys
input = sys.stdin.readline

def solution():
    N, M, B = map(int,input().split())
    board = [list(map(int,input().split())) for i in range(N)]

    TOTAL = 0
    for i in range(N):
        TOTAL += sum(board[i])
    HIGHEST_Y = (TOTAL + B) // (N * M)


    answerCost, answerHeight = 128000001, 257
    currentY = HIGHEST_Y
    while(currentY >= 0):
        calculateCost = calculate(N, M, board, currentY)
        if calculateCost < answerCost:
            answerCost = calculateCost
            answerHeight = currentY
        else:
            break
        currentY -= 1
    print(answerCost, answerHeight)

def calculate(N, M, board, y):
    cost = 0
    for i in range(N):
        for j in range(M):
            if board[i][j] <= y:
                cost += y - board[i][j]
            else:
                cost += 2 * (board[i][j] - y)
    return cost
    
solution()