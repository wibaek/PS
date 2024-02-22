n = int(input())
aa = list()
for x in range(n):
    a,b = map(int,input().split())
    aa.append(a+b)
for x in aa:
    print(x)