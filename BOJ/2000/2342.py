# 2024 - 03 - 30
targets = list(map(int, input().split()))
n = len(targets) - 1
max = 4 * 100001

dp = [[[max for _ in range(5)] for _ in range(5)] for _ in range(len(targets))]

dp[0][0][0] = 0

a_to_b = [
    [-1, 2, 2, 2, 2],
    [-1, 1, 3, 4, 3],
    [-1, 3, 1, 3, 4],
    [-1, 4, 3, 1, 3],
    [-1, 3, 4, 3, 1],
]

for cur in range(n):
    target = targets[cur]
    for i in range(5):
        for j in range(5):
            if dp[cur][i][j] == max:
                continue
            else:
                dp[cur + 1][target][j] = min(
                    dp[cur + 1][target][j], dp[cur][i][j] + a_to_b[i][target]
                )
                dp[cur + 1][i][target] = min(
                    dp[cur + 1][i][target], dp[cur][i][j] + a_to_b[j][target]
                )

answer = max
for i in range(5):
    for j in range(5):
        if dp[-1][i][j] != -1:
            answer = min(answer, dp[-1][i][j])

print(answer)
