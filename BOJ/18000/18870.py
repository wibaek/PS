# 210730 solved
def solution():
    n = int(input())
    coord = list(map(int, input().split()))
    coordSet = list(set(coord))
    coordSet.sort()
    compress = dict()
    for i in range(len(coordSet)):
        compress[coordSet[i]] = i
    answer = []
    for i in coord:
        answer.append(str(compress[i]))
    print(" ".join(answer))
    
solution()