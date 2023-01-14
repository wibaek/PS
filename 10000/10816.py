# 210726 solved
def solution():
    N = int(input())
    nCards = list(map(int, input().split()))
    M = int(input())
    pros = list(map(int, input().split()))
    count = {}
    answer = []
    for card in nCards:
        if card in count:
            count[card] += 1
        else:
            count[card] = 1
    for pro in pros:
        if pro in count:
            answer.append(str(count[pro]))
        else:
            answer.append("0")
    print(" ".join(answer))   
    
solution()