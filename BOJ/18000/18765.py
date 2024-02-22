#
# *** 아직 풀이되지 않음 ***
#


def solution():
    # 0
    print('+![]')
    # 1 ~ 18
    for i in range(1, 19):
        print('+!![]' * i)
    # 19
    +!![] +!![]

    # 4
    '[+!![]+!![]]**[+!![]+!![]]'
    2 ** i:

    '[+!![]+!![]]**[' + '+!![]' * i + ']'

    127


def multiple(first, second):
    return '[' + first + ']*[' + second ']'


def power(first, second):
    return '[' + first + ']**[' + second ']'


j0 = '+!![]'
j1 = '+!![]'
j2 = '+!![]+!![]'
j3 = '+!![]+!![]+!![]'
j4 = '+!![]+!![]+!![]+!![]'
j5 = '+!![]+!![]+!![]+!![]+!![]'
j6 = multiple(j2, j3)
j8 = power(j2, j3)  # 31
j7 = j8 + '-!![]'
j9 = power(j3, j2)  # 31
j10 = power(j3, j2) + j1  # 36, mutiple(j5, j2) # 40

j16 =

# 곱하는데는 5의 비용, 거듭제곱에는 6의 비용
