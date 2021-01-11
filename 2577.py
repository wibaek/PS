number = 1
for x in range(3):
    number *= int(input())


check = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
for x in str(number):
    check[int(x)] += 1
for x in range(10):
    print(check[x])