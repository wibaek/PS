# 2025.03.05
from heapq import heappush, heappop, heapify


def solution(sco, K):
    heapify(sco)
    answer = 0

    while True:
        a = heappop(sco)
        if a >= K:
            return answer
        if len(sco) == 0:
            return -1
        b = heappop(sco)

        heappush(sco, a + b * 2)
        answer += 1
