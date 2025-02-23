# 2025.02.23


## 1차
## 효율성 테스트에서 런타임 에러 발생. 시간제한에 걸리면 런타임 제어로 뜨는듯... 말이되나?
def solution(raw_land):
    answer = 0

    global land
    land = [[0 for _ in range(len(raw_land[0]) + 2)] for _ in range(len(raw_land) + 2)]

    for i in range(len(raw_land)):
        for j in range(len(raw_land[0])):
            land[i + 1][j + 1] = raw_land[i][j]

    ys = len(land)
    xs = len(land[0])

    global can_reach
    can_reach = [set() for _ in range(xs)]  # i에서 도달할 수 있는 오일덩어리의 집합
    global oil_count
    oil_count = 2
    global oil_size
    oil_size = [0 for _ in range(25000)]

    for i in range(1, ys - 1):
        for j in range(1, xs - 1):
            dfs(i, j, oil_count)
            oil_count += 1

    answer = 0
    for s in can_reach:
        count = 0
        for e in s:
            count += oil_size[e]
        answer = max(answer, count)

    return answer


def dfs(y, x, num):
    if land[y][x] != 1:
        return

    land[y][x] = num
    oil_size[num] += 1
    can_reach[x].add(num)

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    for i in range(4):
        dfs(y + dy[i], x + dx[i], num)


## 2차
## 런타임 오류 -> 파이썬의 재귀 한계로 보고 한계 풀어줌. 그러나 2개 런타임 오류. 메모리 초과일까?
import sys

sys.setrecursionlimit(250_001)


def solution(raw_land):
    answer = 0

    global land
    land = [[0 for _ in range(len(raw_land[0]) + 2)] for _ in range(len(raw_land) + 2)]

    for i in range(len(raw_land)):
        for j in range(len(raw_land[0])):
            land[i + 1][j + 1] = raw_land[i][j]

    ys = len(land)
    xs = len(land[0])

    global can_reach
    can_reach = [set() for _ in range(xs)]  # i에서 도달할 수 있는 오일덩어리의 집합
    global oil_count
    oil_count = 2
    global oil_size
    oil_size = [0 for _ in range(25000)]

    for i in range(1, ys - 1):
        for j in range(1, xs - 1):
            if land[i][j] != 1:
                continue
            dfs(i, j, oil_count)
            oil_count += 1

    answer = 0
    for s in can_reach:
        count = 0
        for e in s:
            count += oil_size[e]
        answer = max(answer, count)

    return answer


dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def dfs(y, x, num):
    if land[y][x] != 1:
        return

    land[y][x] = num
    oil_size[num] += 1
    can_reach[x].add(num)

    for i in range(4):
        if land[y + dy[i]][x + dx[i]] == 1:
            dfs(y + dy[i], x + dx[i], num)


## 3차
## 계산을 잘못해서 25만을 2.5만으로 하고 있었다
import sys

sys.setrecursionlimit(250_001)


def solution(raw_land):
    answer = 0

    global land
    land = [[0 for _ in range(len(raw_land[0]) + 2)] for _ in range(len(raw_land) + 2)]

    for i in range(len(raw_land)):
        for j in range(len(raw_land[0])):
            land[i + 1][j + 1] = raw_land[i][j]

    ys = len(land)
    xs = len(land[0])

    global can_reach
    can_reach = [set() for _ in range(xs)]  # i에서 도달할 수 있는 오일덩어리의 집합
    global oil_count
    oil_count = 2
    global oil_size
    oil_size = [0 for _ in range(250001)]

    for i in range(1, ys - 1):
        for j in range(1, xs - 1):
            if land[i][j] != 1:
                continue
            dfs(i, j, oil_count)
            oil_count += 1

    answer = 0
    for s in can_reach:
        count = 0
        for e in s:
            count += oil_size[e]
        answer = max(answer, count)

    return answer


dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def dfs(y, x, num):
    if land[y][x] != 1:
        return

    land[y][x] = num
    oil_size[num] += 1
    can_reach[x].add(num)

    for i in range(4):
        if land[y + dy[i]][x + dx[i]] == 1:
            dfs(y + dy[i], x + dx[i], num)
