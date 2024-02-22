def check(level, startX, startY):
    '''
    startX ~ startX + 2^level - 1
    startX + 2^level ~ startX + 2^(level) - 1
    '''
    global table, white, blue

    current = 0
    for y in range(startY, startY + 2 ** level):
        for x in range(startX, startX + 2 ** level):
            current += table[y][x]
    if current == 0:
        white += 1
    elif current == 4 ** (level):
        blue += 1
    else:
        check(level - 1, startX, startY)
        check(level - 1, startX + 2**(level - 1), startY)
        check(level - 1, startX, startY + 2 ** (level - 1))
        check(level - 1, startX + 2 ** (level - 1), startY + 2 ** (level - 1))


def solution():
    global table, white, blue
    table = []

    white = 0  # 0
    blue = 0  # 1

    n = int(input())
    for y in range(n):
        table.append(list(map(int, input().split())))

    count = 0
    while(n != 1):
        n /= 2
        count += 1

    check(count, 0, 0)
    print(white)
    print(blue)


solution()
