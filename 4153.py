# 210726 solved
def solution():
    while(True):
        a, b, c = map(int, input().split())
        if a+b+c == 0:
            break
        print(calc(a, b, c))
    
    
def calc(a, b, c):
    array = [a, b, c]
    array.sort()
    if array[0]**2 + array[1]**2 == array[2]**2:
        return "right"
    else:
        return "wrong"
    
solution()