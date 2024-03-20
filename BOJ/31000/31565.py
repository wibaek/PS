# 2024-03-20
# 배낭 문제
import datetime

# 입력: 날짜
his_discharge_date = list(map(int, input().split()))
my_discharge_date = list(map(int, input().split()))
date_diff = (
    datetime.datetime(my_discharge_date[0], my_discharge_date[1], my_discharge_date[2])
    - datetime.datetime(
        his_discharge_date[0], his_discharge_date[1], his_discharge_date[2]
    )
).days

# 입력: 계획
energy, task_count = map(int, input().split())
tasks = []  # (여유, day)
for i in range(task_count):
    task, energy_cost, value = list(map(int, input().split()))
    if task == 3:
        tasks.append((energy_cost, value * 30))
    else:
        tasks.append((energy_cost, value))

# 풀이
dp = [0 for _ in range(energy + 1)]
for energy_cost, day_save in tasks:
    for i in range(energy, energy_cost - 1, -1):
        dp[i] = max(dp[i], dp[i - energy_cost] + day_save)

answer = abs(date_diff - dp[energy])
print(answer)
