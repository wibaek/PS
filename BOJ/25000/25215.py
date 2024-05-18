# 2024 - 05 - 18
seq = input()

case_seq = []  # 0 if lower, 1 if upper

dp = (
    [0],
    [1],
)  # i 번째 문자까지 처리했을때 lower일때의 사용 버튼 최소값, upper일때의 최소값

for i in seq:
    if i.islower():
        case_seq.append(0)
    else:
        case_seq.append(1)

for i in case_seq:
    lower_last = dp[0][-1]
    upper_last = dp[1][-1]
    if i == 0:
        dp[0].append(min(lower_last + 1, upper_last + 2))
        dp[1].append(min(lower_last + 2, upper_last + 2))
    else:
        dp[0].append(min(lower_last + 2, upper_last + 2))
        dp[1].append(min(lower_last + 2, upper_last + 1))

print(min(dp[0][-1], dp[1][-1]))
