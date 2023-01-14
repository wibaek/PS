MAX_LENGTH = 10


def solution():
    CASE = int(input())
    caseBoard = list(map(int, input().split()))

    caseBoard.sort(key=lambda x: sortKey(x), reverse=True)

    answer = ''
    for i in caseBoard:
        answer += str(i)

    print(int(answer))


def sortKey(x):
    base = int(str(x) + str(x)[0]*(MAX_LENGTH - len(str(x))))
    baseNumber = int(str(x)[0])
    subNumber = int(str(x)[0])

    for i in str(x):
        if int(i) != baseNumber:
            subNumber = int(i)
            break

    if subNumber < baseNumber:
        base -= 0.01 * (MAX_LENGTH - len(str(x)))
    elif subNumber > baseNumber:
        base += 0.01 * (MAX_LENGTH - len(str(x)))

    return base


solution()

#################### 프로그래머스 버전 ####################

# MAX_LENGTH = 4


# def solution(caseBoard):

#     caseBoard.sort(key=lambda x: sortKey(x), reverse=True)

#     answer = ''
#     for i in caseBoard:
#         answer += str(i)


#     return str(int(answer))


# def sortKey(x):
#     base = int(str(x) + str(x)[0]*(MAX_LENGTH - len(str(x))))
#     baseNumber = int(str(x)[0])
#     subNumber = int(str(x)[0])

#     for i in str(x):
#         if int(i) != baseNumber:
#             subNumber = int(i)
#             break

#     if subNumber < baseNumber:
#         base -= 0.01 * (MAX_LENGTH - len(str(x)))
#     elif subNumber > baseNumber:
#         base += 0.01 * (MAX_LENGTH - len(str(x)))

#     return base
