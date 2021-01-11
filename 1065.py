n = int(input())

hansu = []
count = 0

for x in range(1,10):
    hansu.append(x)

for x in range(10,100):
    hansu.append(x)

for x in range(100,1000):
    q = str(x)
    if int(q[0]) + int(q[2]) == 2* int(q[1]):
        hansu.append(x)

for x in hansu:
    if x<= n:
        count+=1
print(count)