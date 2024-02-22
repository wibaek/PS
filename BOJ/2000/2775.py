T = int(input())

room = [[0 for i in range(15)] for j in range(15)]
for i in range(1, 15):
    room[0][i] = i

for i in range(1, 15):
    total = 0
    for j in range(1, 15):
        total += room[i - 1][j]
        room[i][j] = total

for i in range(T):
    k = int(input())
    n = int(input())
    print(room[k][n])
