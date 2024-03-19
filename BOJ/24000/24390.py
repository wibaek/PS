# 2024-03-19
minutes, seconds = map(int, input().split(":"))
time = minutes * 60 + seconds

que = [0, 30]
record = [-1 for _ in range(3601)]
record[30] = 1
record[0] = 1
CHOICE = [10, 30, 60, 600]

cur = 0
if time == 0:
    print(0)
    exit()
while len(que) > cur:
    number = que[cur]
    cur += 1
    if number == time:
        print(record[number])
        break
    for c in CHOICE:
        next_number = number + c
        if next_number < 3601 and record[next_number] == -1:
            record[next_number] = record[number] + 1
            que.append(next_number)
