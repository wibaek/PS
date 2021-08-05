# 210726 solved
import math
fact = math.factorial
def solution(n, k):
    return fact(n)/(fact(n-k)*fact(k))

n, k = map(int, input().split())
print(int(solution(n, k)))