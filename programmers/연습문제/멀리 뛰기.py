# 2025.02.19


def solution(n):
    dp = [0 for _ in range(n + 2)]
    dp[0] = 1
    dp[1] = 2

    idx = 2
    while idx < n:
        dp[idx] = (dp[idx - 1] + dp[idx - 2]) % 1234567
        idx += 1
    return dp[n - 1]
