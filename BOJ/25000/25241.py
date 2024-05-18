# 2024 - 05 - 18
n = int(input())
seq = list(map(int, input().split()))

dp = []
dp_min = [seq[0]]

for i in range(n):
    value = seq[i]
    if i > 0:
        dp_min.append(min(dp_min[i - 1], value))
        dp.append(max(dp[i - 1], value - dp_min[i]))
    else:
        dp.append(0)

    print(dp[i], end=" ")
