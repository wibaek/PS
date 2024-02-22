a = input()
print(a[0], end="")
for i in range(len(a)):
    if a[i] == "-":
        print(a[i + 1], end="")
