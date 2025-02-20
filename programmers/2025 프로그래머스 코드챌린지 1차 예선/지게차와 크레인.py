# 2025.02.19

"""
o: outside
b: blank(not outside)
"""

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def forklift(abc: str) -> None:
    for y in range(1, y_len - 1):
        for x in range(1, x_len - 1):
            if table[y][x] == abc:
                for i in range(4):
                    if table[y + dy[i]][x + dx[i]] == "o":
                        table[y][x] = "oo"
                        break

    # oo -> o
    for y in range(y_len):
        for x in range(x_len):
            if table[y][x] == "oo":
                table[y][x] = "o"

    for y in range(y_len):
        for x in range(x_len):
            check_o(y, x)


def crain(abc: str) -> None:
    for y in range(1, y_len - 1):
        for x in range(1, x_len - 1):
            if table[y][x] == abc:
                table[y][x] = "t"

    for y in range(y_len):
        for x in range(x_len):
            check_o(y, x)

    for y in range(y_len):
        for x in range(x_len):
            if table[y][x] == "t":
                table[y][x] = "b"


def check_o(y, x) -> None:
    if table[y][x] != "o":
        return

    for i in range(4):
        if 0 <= y + dy[i] <= y_len - 1 and 0 <= x + dx[i] <= x_len - 1:
            if table[y + dy[i]][x + dx[i]] == "t" or table[y + dy[i]][x + dx[i]] == "b":
                table[y + dy[i]][x + dx[i]] = "o"
                check_o(y + dy[i], x + dx[i])


def count_container() -> int:
    count = 0
    for y in table:
        for x in y:
            if x != "o" and x != "b":
                count += 1

    return count


def solution(storage, requests):
    global y_len, x_len
    y_len, x_len = len(storage) + 2, len(storage[0]) + 2

    global table
    table = [["o" for _ in range(x_len)] for _ in range(y_len)]

    for y in range(y_len - 2):
        for x in range(x_len - 2):
            table[y + 1][x + 1] = storage[y][x]

    for req in requests:
        if len(req) == 2:
            crain(req[0])
        else:
            forklift(req)

    return count_container()
