x,y,w,h = map(int,input().split())

smallest = 1001

if x < smallest:
    smallest = x
if y < smallest:
    smallest = y
if w-x < smallest:
    smallest = w-x
if h-y < smallest:
    smallest = h-y
print(smallest)