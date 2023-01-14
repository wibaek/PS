def solution():
    n = int(input())
    cost = [[0, 0, 0]]
    for i in range(1, n + 1):
        red, green, blue = map(int, input().split())
        cost.append([red + min(cost[i - 1][1], cost[i - 1][2]), green + min(cost[i - 1]
                    [0], cost[i - 1][2]), blue + min(cost[i - 1][0], cost[i - 1][1])])
    print(min(cost[n]))


solution()
