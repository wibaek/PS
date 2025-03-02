# 2025.03.03


def solution(s):
    count = 0
    for p in s:
        count = count + 1 if p == "(" else count - 1
        if count < 0:
            return False

    if count != 0:
        return False

    return True
