# UNSOlVED
import sys

input = sys.stdin.readline
sys.setrecursionlimit(10000)


def pack(cap: int, item: int) -> int:
    global N, size, value, cache
    if item == N:
        return 0

    if cache[cap][item] != -1:
        return cache[cap][item]

    ret = pack(cap, item + 1)
    if cap >= size[item]:
        ret = max(ret, (pack(cap - size[item], item + 1) + value[item]))
    cache[cap][item] = ret
    return ret


def solution():
    global N, size, value, cache
    cache = [[-1 for _ in range(100)] for _ in range(100001)]
    N, K = map(int, input().split())
    value = []
    size = []

    for _ in range(N):
        s, v = map(int, input().split())
        size.append(s)
        value.append(v)
    print(pack(K, 0))


solution()
