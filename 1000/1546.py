n = int(input())

ns = list(map(float,input().split()))

biggest = max(ns)
#print(biggest)

for x in range(n):
    ns[x] = (ns[x] / biggest)*100

#print(ns)

print(sum(ns)/n)
