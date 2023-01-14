hour , min = map(int,input().split())

min -= 45

if min<0:
    hour -= 1
    min += 60
if hour == -1:
    hour = 23

print(hour,min)