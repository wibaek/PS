def solution():
    n = int(input())
    pList = list(map(int, input().split()))

    pList.sort()
    answer = 0
    for i in range(n):
        answer += pList[i] * (n - i)

    print(answer)


solution()
