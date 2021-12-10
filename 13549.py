from collections import deque

def solution() -> None:
    dq = deque()
    MAXCACHE = 100000
    cache = [-1 for _ in range(MAXCACHE+1)]
    
    N, K = map(int, input().split())
    cache[N] = 0

    dq.append(N)
    while(dq):
        x = dq.pop()
        if x == K:
            print(cache[x])
            return
        for nx in (x*2, x-1, x+1):
            if 0 <= nx <= MAXCACHE and cache[nx] == -1:
                if nx == x*2:
                    dq.append(nx)
                    cache[nx] = cache[x]
                else:
                    dq.appendleft(nx)
                    cache[nx] = cache[x]+1

solution()