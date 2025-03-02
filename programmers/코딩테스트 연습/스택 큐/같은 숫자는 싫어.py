# 2025.03.03


def solution(arr):
    answer = [arr[0]]
    for e in arr[1:]:
        if e == answer[-1]:
            continue
        answer.append(e)
    return answer
