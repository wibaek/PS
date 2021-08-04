def solution():
    n = int(input())
    perm = list(map(int, input().split()))
    cache = [-1 for i in range(n)]
    print(max([lis(i, perm, cache, n) for i in range(0,n)]))

def lis(n, perm, cache, maxn):
    value = cache[n]
    if value != -1:
        return value
    value = 1
    for i in range(n+1, maxn):
        if perm[n] < perm[i]:
            value = max(value, 1 + lis(i, perm, cache, maxn))
    cache[n] = value
    return value

solution()