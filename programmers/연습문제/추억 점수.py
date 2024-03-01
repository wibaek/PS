def solution(name, yearning, photo):
    N = len(name)
    d = dict()
    for i in range(N):
        d[name[i]] = yearning[i]

    answer = []
    for p in photo:
        total = 0
        for n in p:
            if n in d:
                total += d[n]
        answer.append(total)
    return answer
