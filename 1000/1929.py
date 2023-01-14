# 210725 solved
def solution(m, n):
    sosuList = getSosu()
    if m == 1:
        m = 2
    for i in range(m, n+1):
        isPrime = True
        for sosu in sosuList:
            if sosu >= i:
                break
            if i%sosu == 0:
                isPrime = False
                break
        if isPrime:
            print(i)
            
def getSosu():
    sosus = [2, 3]
    current = 5
    while current <= 1001:
        isSosu = True
        for sosu in sosus:
            if current % sosu == 0:
                isSosu = False
                break
        if isSosu:
            sosus.append(current)
        current += 2
    return sosus
        
m, n = map(int, input().split())
solution(m, n)