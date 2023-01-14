def solution():
    N, M = map(int,input().split())
    board = [list(input()) for _ in range(N)]

    answer = 65
    for i in range(0, N - 8 + 1):
        for j in range(0, M - 8 + 1):
            calcValue = calc(i, j, board)
            answer = answer if answer < calcValue else calcValue
    print(answer)
            
def calc(startI, startJ, board):
    case = ['B', 'W']
    caseAnswer = [0, 0]
    for i in range(startI, startI + 8):
        for j in range(startJ, startJ + 8):
            caseAnswer[0 if board[i][j] == case[(i + j) % 2] else 1] += 1

    return caseAnswer[0] if caseAnswer[0] < caseAnswer[1] else caseAnswer[1]

solution()