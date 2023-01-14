n = int(input())

for x in range(n,0,-1):
    print(" "*(n-x),end="")
    print("*"*(2*x-1))
for x in range(2,n+1,1):
    print(" "*(n-x),end="")
    print("*"*(2*x-1))