total = 0

for x in range(5):
    a = int(input())
    if a <40:
        a = 40
    total += a
try:
    print(int(total/5))
except:
    print(total/5)