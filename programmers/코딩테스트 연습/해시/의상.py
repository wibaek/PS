# 2025.03.05


def solution(clothes):
    closet = {}
    for c in clothes:
        if c[1] in closet:
            closet[c[1]] += 1
        else:
            closet[c[1]] = 1

    answer = 1
    for key, val in closet.items():
        answer = answer * (val + 1)
    return answer - 1
