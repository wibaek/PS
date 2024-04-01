# 2024 - 04 - 01
n = int(input())  # 2 <= N <= 100,000
cards = list(map(int, input().split()))
win_count = [0 for _ in range(n)]

card_index = [-1 for _ in range(1_000_001)]
for i in range(n):
    card_index[cards[i]] = i

for i in range(1, 1_000_001):
    if card_index[i] == -1:
        continue
    for j in range(i * 2, 1_000_001, i):
        if card_index[j] == -1:
            continue
        win_count[card_index[i]] += 1
        win_count[card_index[j]] -= 1

print(" ".join(map(str, win_count)))
