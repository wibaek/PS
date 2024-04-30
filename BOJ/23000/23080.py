# 2024 - 04 - 30
n = int(input())
password = input()
answer = ""
for i in range(0, len(password), n):
    answer += password[i]

print(answer)
