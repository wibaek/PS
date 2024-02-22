a = int(input())
ans = 0
while a >= 10:
    a = str(a)
    ret = 0
    for i in a:
        ret += int(i)
    a = ret
    ans += 1
print(ans)
if a % 3 == 0:
    print("YES")
else:
    print("NO")

# pypy를 써야 간신히 시간초과를 벗어나는 문제.
# 최대 100만자리가 들어오지만 첫 계산 이후로는 최대 900만 -> 7자리 임으로 첫번쨰가 관건
# 처음에 굳이 int str로 바꾸지말고 받은거 그대로 첫번째만 효율적으로 계산하고 나머지는 재귀해도 괜찮을듯.
