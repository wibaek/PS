w, h, k = map(int, input().split())
n = int(input())
y_cutting = [0] + list(map(int, input().split())) + [h]
m = int(input())
x_cutting = [0] + list(map(int, input().split())) + [w]

x_piece = []
y_piece = []
for i in range(m + 1):
    if x_cutting[i + 1] - x_cutting[i] != 0:
        x_piece.append(x_cutting[i + 1] - x_cutting[i])
for i in range(n + 1):
    if y_cutting[i + 1] - y_cutting[i] != 0:
        y_piece.append(y_cutting[i + 1] - y_cutting[i])

x_piece.sort()
y_piece.sort()

total = 0

cur_y = len(y_piece) - 1
for cur_x in range(len(x_piece)):
    while cur_y > -1 and x_piece[cur_x] * y_piece[cur_y] > k:
        cur_y -= 1
    total += cur_y + 1

print(total)
