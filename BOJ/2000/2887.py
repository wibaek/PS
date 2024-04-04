# 2024 - 04 - 04
n = int(input())

coord_list = [[], [], []]
gap_list = []
for i in range(n):
    x, y, z = map(int, input().split())
    coord_list[0].append((x, i))
    coord_list[1].append((y, i))
    coord_list[2].append((z, i))

for coord in coord_list:
    coord.sort()
    for i in range(1, n):
        gap_list.append((coord[i][0] - coord[i - 1][0], coord[i - 1][1], coord[i][1]))

gap_list.sort()

edge_count = 0
answer = 0
parent = list(range(n))


def find_set(x):
    if parent[x] != x:
        parent[x] = find_set(parent[x])
    return parent[x]


def union_sets(x, y):
    x_root = find_set(x)
    y_root = find_set(y)
    if x_root != y_root:
        parent[x_root] = y_root


def find_sets(x, y):
    return find_set(x) != find_set(y)


for gap in gap_list:
    if edge_count == n - 1:
        break

    x, y = gap[1], gap[2]
    if not find_sets(x, y):
        continue

    union_sets(x, y)
    edge_count += 1
    answer += gap[0]

print(answer)
