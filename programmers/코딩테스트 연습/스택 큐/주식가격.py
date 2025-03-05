# 2025.03.05


def solution(prices):
    leng = len(prices)
    answer = [-1 for i in range(leng)]
    idx_stack = []

    for i in range(leng):
        while idx_stack and prices[idx_stack[-1]] > prices[i]:
            answer[idx_stack[-1]] = i - idx_stack[-1]
            idx_stack.pop()
        idx_stack.append(i)

    for i in idx_stack:
        answer[i] = leng - i - 1

    return answer


if __name__ == "__main__":
    print(solution([1, 2, 3, 4, 5]))
