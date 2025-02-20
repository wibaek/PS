# 2025.02.19

### first try
### Can't solve case like 9 8 7 6 5 4 3 2 1 9 10


def solution(numbers):
    answer = [-1 for _ in range(len(numbers))]
    biggest_num = -1

    for idx in range(len(numbers) - 1, -1, -1):
        biggest_num = max(biggest_num, numbers[idx])
        if numbers[idx] >= biggest_num:
            continue
        for idx2 in range(idx, len(numbers)):
            if numbers[idx] < numbers[idx2]:
                answer[idx] = numbers[idx2]
                break
            if numbers[idx] > numbers[idx2] and numbers[idx] < answer[idx2]:
                answer[idx] = answer[idx2]
                break

    return answer


### second try


def solution(numbers):
    ll = len(numbers)
    answer = [-1 for _ in range(ll)]

    stack = []
    for i in range(ll):
        while True:
            if len(stack) > 0 and stack[-1][1] < numbers[i]:
                answer[stack[-1][0]] = numbers[i]
                stack.pop()
                continue
            break

        stack.append((i, numbers[i]))

    return answer
