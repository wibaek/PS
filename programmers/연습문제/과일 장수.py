# 2025.02.17


def solution(k, m, score):
    score.sort()
    score.reverse()
    if len(score) % m != 0:
        score = score[0 : -(len(score) % m)]

    answer = 0
    for i in range(len(score) // m):
        candidate = score[i * m : (i + 1) * m]
        answer += min(candidate) * m

    return answer
