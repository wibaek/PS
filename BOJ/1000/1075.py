n = int(input())
f = int(input())
n = n // 100

for i in range(100):
    if (n * 100 + i) % f == 0:
        if i < 10:
            print("0", end="")
        print(i)
        break
