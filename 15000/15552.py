import sys
n = int(input())
aa = list()
for x in range(n):
    a,b = map(int,sys.stdin.readline().split())
    print(a+b)
