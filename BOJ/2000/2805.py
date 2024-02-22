import sys

input = sys.stdin.readline


def is_length_enough(height: int, criteria: int, tree: list):
    for i in tree:
        if i > height:
            criteria -= i - height
            if criteria <= 0:
                return True

    return False


n, m = map(int, input().split())  # 나무의 수, 필요한 나무의 길이
tree = list(map(int, input().split()))
tree_sum = [tree[0]]
for i in range(1, n):
    tree_sum.append(tree_sum[i - 1] + tree[i])
total_tree_length = tree_sum[-1]
tree.sort()
start = 0
end = 2000000000
ans = -1

while start <= end:
    mid = (start + end) // 2
    if is_length_enough(mid, m, tree):
        ans = mid
        start = mid + 1
    else:
        end = mid - 1

print(ans)
