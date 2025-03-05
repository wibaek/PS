def toString(number: int) -> str:
    number = str(number) * 3
    return number


def solution(numbers):
    numbers.sort(key=lambda x: toString(x), reverse=True)
    numbers = list(map(str, numbers))
    answer = str(int("".join(numbers)))
    return answer
