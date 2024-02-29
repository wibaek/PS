def solution(participant, completion):
    d = dict()
    for c in completion:
        if c in d:
            d[c] += 1
        else:
            d[c] = 1
    for p in participant:
        if p not in d:
            return p
        elif d[p] == 0:
            return p
        else:
            d[p] -= 1
