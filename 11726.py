def solution(n: int) -> int:
    cache = [1, 1, 2]
    for i in range(3, 1001):
        cache.append((cache[i-1]+cache[i-2])%10007)
    return cache[n]
    
print(solution(int(input())))