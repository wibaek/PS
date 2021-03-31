import sys
input = sys.stdin.readline


def solution():
    N, M = map(int, input().split())
    D = []
    for i in range(N):
        D.append(input().rstrip())
    D.sort()

    DB = []
    for i in range(M):
        get = input().rstrip()
        if binary_search(get, D):
            DB.append(get)

    DB.sort()
    print(len(DB))
    for i in DB:
        print(i)


def binary_search(target, data):
    start = 0
    end = len(data) - 1

    while start <= end:
        mid = (start + end) // 2

        if data[mid] == target:
            return True  # 함수를 끝내버린다.
        elif data[mid] < target:
            start = mid + 1
        else:
            end = mid - 1

    return False


solution()
