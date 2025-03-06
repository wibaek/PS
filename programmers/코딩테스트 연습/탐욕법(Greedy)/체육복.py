# 2025.03.06


def solution(n, lost, reserve):
    for l in set(lost):
        if l in reserve:
            lost.remove(l)
            reserve.remove(l)

    answer = n - len(lost)
    lost.sort()
    for l in lost:
        if l - 1 in reserve:
            reserve.remove(l - 1)
            answer += 1
            continue

        if l + 1 in reserve:
            reserve.remove(l + 1)
            answer += 1
            continue

    return answer
