# 2025.03.05


def solution(citations):
    # h index는 0~1000 사이의 값
    leng = len(citations)

    count = [0 for _ in range(1001)]
    for c in citations:
        count[min(c, 1000)] += 1
    for i in range(999, -1, -1):
        count[i] += count[i + 1]

    # count[i]는 i보다 많이 인용된 논문의 개수

    lo = 0
    hi = 1000
    while lo < hi:
        mid = (lo + hi) // 2
        if count[mid] < mid:
            hi = mid
        else:
            lo = mid + 1

    return lo - 1
