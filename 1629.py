# solved without dynamic  programming     
import sys
sys.setrecursionlimit(10**6)

def solution(a, b, c):
    cache = {1:a%c}
    answer = req(a, b, c, cache)%c   
    return answer

def req(a, b, c, cache):
    if cache.get(b) == None:
        if b%2 == 0:
            return (req(a, b/2, c, cache)%c)**2
        else:
            return ((req(a, (b-1)/2, c, cache)**2)%c)*cache[1]
    else:
        return cache[b]


a, b, c = map(int, input().split())
print(solution(a, b, c))