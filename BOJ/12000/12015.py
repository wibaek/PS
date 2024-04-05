# 2024 - 04 - 05
from bisect import bisect_left

n = int(input())
l = list(map(int, input().split()))
smallest = [l[0]]  # smallest[i] = 길이가 i인 증가 부분 수열 중 가장 작은 마지막 수

for i in range(1, n):
    num = l[i]
    idx = bisect_left(smallest, num)
    if idx == len(smallest):
        smallest.append(num)
    else:
        smallest[idx] = num

print(len(smallest))
