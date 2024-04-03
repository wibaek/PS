# 2024 - 04 - 03
import sys

sys.setrecursionlimit(30001)

kid_count, relation_count, k = map(int, input().split())
candies = list(map(int, input().split()))
relations = [tuple(map(int, input().split())) for _ in range(relation_count)]
kids = [{"friend_with": []} for _ in range(kid_count)]

for relation in relations:
    a, b = relation
    a -= 1
    b -= 1
    kids[a]["friend_with"].append(b)
    kids[b]["friend_with"].append(a)


visited = [False for _ in range(kid_count)]
groups = []  # [인원 수, 사탕 수]
group_count = 0


def dfs(kid: int, group: int):
    if visited[kid]:
        return
    visited[kid] = True
    groups[group][0] += 1
    groups[group][1] += candies[kid]

    for friend in kids[kid]["friend_with"]:
        if visited[friend]:
            continue
        dfs(friend, group)


for i in range(kid_count):
    if visited[i]:
        continue
    group_count += 1
    groups.append([0, 0])
    dfs(i, group_count - 1)

answer = 0
dp = [
    0 for _ in range(kid_count + 1)
]  # dp[i] = i명 이하의 사람들이 가질 수 있는 최대 사탕 수

for group in groups:
    for i in range(kid_count, group[0] - 1, -1):
        dp[i] = max(dp[i], dp[i - group[0]] + group[1])

print(dp[k - 1])
