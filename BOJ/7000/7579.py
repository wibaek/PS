# 2024 - 03 - 28
n, memory_need = map(int, input().split())
using_memory = list(map(int, input().split()))
cost = list(map(int, input().split()))

# dp[i][j] : i번째 앱까지 측정, j만큼의 비용을 썼을 때 확보할 수 있는 최대 메모리
dp = [[0 for _ in range(10001)] for _ in range(n)]

dp[0][cost[0]] = using_memory[0]
for i in range(1, n):
    for j in range(10001):
        if j - cost[i] >= 0:
            dp[i][j] = max(dp[i - 1][j - cost[i]] + using_memory[i], dp[i - 1][j])
        else:
            dp[i][j] = dp[i - 1][j]


for i in range(10001):
    if dp[-1][i] >= memory_need:
        print(i)
        break
