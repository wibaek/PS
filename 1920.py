def binary_search(target, data):
    start = 0
    end = len(data) - 1

    while start <= end:
        mid = (start + end) // 2

        if data[mid] == target:
            return True # 함수를 끝내버린다.
        elif data[mid] < target:
            start = mid + 1
        else:
            end = mid -1

    return False

n = int(input())
board = list(map(int,input().split()))
board.sort()

caseN = int(input())
case = list(map(int,input().split()))

for i in case:
    if binary_search(i, board):
        print('1')
    else:
        print('0')

