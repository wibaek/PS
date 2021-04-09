def solution(n):
    return count(0, n)


def count(current, end):
    if current < end:
        return count(current + 1, end) + count(current + 2, end) + count(current + 3, end)
    elif current > end:
        return 0
    else:
        return 1


def main():
    n = int(input())
    for i in range(n):
        print(solution(int(input())))


main()
