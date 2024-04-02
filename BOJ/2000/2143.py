# 2024 - 04 - 02
def count_elements(arr):
    counts = {}
    for num in arr:
        if num in counts:
            counts[num] += 1
        else:
            counts[num] = 1
    result = [(key, value) for key, value in counts.items()]
    return result


t = int(input())
n = int(input())
A = list(map(int, input().split()))
m = int(input())
B = list(map(int, input().split()))
answer = 0

dpA = [0 for _ in range(n)]
dpB = [0 for _ in range(m)]

for i in range(n):
    dpA[i] = A[i]
    if i > 0:
        dpA[i] += dpA[i - 1]
for i in range(m):
    dpB[i] = B[i]
    if i > 0:
        dpB[i] += dpB[i - 1]

ableA = []
ableB = []
for i in range(n):
    for j in range(i, n):
        ableA.append(dpA[j] - dpA[i] + A[i])
for i in range(m):
    for j in range(i, m):
        ableB.append(dpB[j] - dpB[i] + B[i])

ableA = count_elements(ableA)
ableB = count_elements(ableB)

ableA.sort()
ableB.sort()

lenA = len(ableA)
lenB = len(ableB)

cur1 = 0
cur2 = lenB - 1

if ableA[cur1][0] + ableB[cur2][0] == t:
    answer += ableA[cur1][1] * ableB[cur2][1]
while cur1 < lenA - 1 or cur2 > 0:
    if cur1 == lenA - 1:
        cur2 -= 1
    elif cur2 == 0:
        cur1 += 1
    else:
        if ableA[cur1][0] + ableB[cur2][0] < t:
            cur1 += 1
        else:
            cur2 -= 1
    if ableA[cur1][0] + ableB[cur2][0] == t:
        answer += ableA[cur1][1] * ableB[cur2][1]

print(answer)
