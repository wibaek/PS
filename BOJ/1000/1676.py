n = int(input())

ans = 1
for i in range(1, n + 1):
    ans *= i

ans = str(ans)
for i in range(1, len(ans) + 1):
    if ans[-i] != "0":
        print(i - 1)
        break
