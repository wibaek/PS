import sys
sys.setrecursionlimit(10000)

def solution():
    # print("solution 한사이클")
    xRange, yRange, k = map(int,input().split())
    answer = 0
    board = [[0 for _ in range(53)] for _ in range(53)]
    checkBoard = [[0 for _ in range(53)] for _ in range(53)]
    coords = []
    for i in range(k):
        coords.append(list(map(int,input().split())))
    # print("좌표값들: ",coords)
    for i, j in coords:
        board[j][i] = 1

    for i in range(yRange):
        for j in range(xRange):
            answer = check(j, i, yRange, xRange, board, checkBoard, answer)
    print(answer)

    
def check(x, y, yRange, xRange, board, checkBoard, answer):
    if board[y][x] == 0 or checkBoard[y][x] == 1:
        # print("1번 케이스")
        return answer
    # print("2번 케이스")
    checkBoard[y][x] = 1

    if (checkBoard[y + 1][x] == 0 and checkBoard[y - 1][x] == 0) and (checkBoard[y][x + 1] == 0 and checkBoard[y][x - 1] == 0):
        # print("answer 증가", answer)
        # print("디버깅",y + 1,x + 1)
        answer += 1
    if x < xRange:
        answer = check(x + 1, y, yRange, xRange, board, checkBoard, answer)
    if y < yRange:
        answer = check(x, y + 1, yRange, xRange, board, checkBoard, answer)
    if x > 0:
        answer = check(x - 1, y, yRange, xRange, board, checkBoard, answer)
    if y > 0:
        answer = check(x, y - 1, yRange, xRange, board, checkBoard, answer)

    return answer


testCase = int(input())

for _ in range(testCase):
    solution()

