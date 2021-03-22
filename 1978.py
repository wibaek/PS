def solution():
    prime = []
    for i in range(2,1001):
        if checkPrime(i, prime):
            prime.append(i)
    
    N = int(input())
    board = list(map(int,input().split()))
    answer = 0
    for i in board:
        if i in prime:
            answer += 1
    print(answer)

def checkPrime(i, prime):
    for j in prime:
        if i % j == 0:
            return False
    return True


solution()