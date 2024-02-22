a,b = input().split()
a1 = ''
b1 = ''

for x in range(len(a)-1,-1,-1):
    a1 += str(a[x])

for x in range(len(b)-1,-1,-1):
    b1 += str(b[x])

# print(a1,b1)

a1 = int(a1)
b1 = int(b1)

# print(a1,b1)

if a1 > b1:
    print(a1)
else:
    print(b1)


