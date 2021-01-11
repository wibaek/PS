n, high = map(int,input().split())

number = list(map(int,input().split()))

biggest = 0

for x in range(0,n-2):
    for y in range(x+1,n-1):
        for z in range(y+1,n):
            if number[x] + number[y] + number[z] <= high:
                if number[x] + number[y] + number[z] > biggest:
                    biggest = number[x] + number[y] + number[z]

print(biggest)
