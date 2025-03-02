# 2025.03.03

from collections import deque


def solution(pri, loc):
    answer = 0

    deq = deque()
    for i in range(len(pri)):
        deq.append((pri[i], loc == i))

    pri.sort()

    while True:
        if deq[0][0] < pri[-1]:
            deq.rotate(-1)
            continue

        answer += 1
        pri.pop()
        if deq[0][1] == True:
            break
        deq.popleft()

    return answer
