a = []

for i in range(5):
    b = input()
    if b in a:
        a.remove(b)
    else:
        a.append(b)

print(a[0])
