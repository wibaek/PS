get = input().split()

total = 0
for x in get:
    total += int(x) ** 2
print(total % 10)
