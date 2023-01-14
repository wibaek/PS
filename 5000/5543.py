total = 0
burger = 9999

for x in range(3):
    a = int(input())
    if a < burger:
        burger = a


bev = 9999
for x in range(2):
    a = int(input())
    if a < bev:
        bev = a

print(bev + burger - 50)