a = list()
for x in range(9):
    a.append(int(input()))
count = 0
big = -1
for x in range(9):
    if a[x] > big:
        big = a[x]
        count = x
print(big)
print(count+1)