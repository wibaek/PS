def solution(n):
    answer = 0
    for i in range(1, n + 1):
        cur = i
        total = 0
        while total < n:
            total += cur
            cur += 1
        if total == n:
            answer += 1

    return answer
