# 210801 solved
cache = dict()
def solution():
    n = int(input())
    for i in range(n):
        c0, c1 = fibo(int(input()))
        print(c0, c1)
        
def fibo(n):
    if n == 0:
        return 1, 0
    elif n == 1:
        return 0, 1
    else:
        global cache
        value = cache.get(n)
        if value == None:
            firstc0, firstc1 = fibo(n-1)
            secondc0, secondc1 = fibo(n-2)
            cache[n] = firstc0 + secondc0, firstc1 + secondc1
        return cache.get(n)
    
solution()