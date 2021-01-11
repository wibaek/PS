nlist = [0 for _ in range(10001)]

for x in range(1,10001):
    total = 0
    total += x
    if x >= 10000:
        total += int(x/10000)
        x %= 10000
    if x >= 1000:
        total += int(x / 1000)
        x %= 1000
    if x >= 100:
        total += int(x / 100)
        x %= 100
    if x >= 10:
        total += int(x / 10)
        x %= 10
    total += x
    if total<=10000:
        nlist[total] += 1
for x in range(1,10001):
    if nlist[x] == 0:
        print(x)