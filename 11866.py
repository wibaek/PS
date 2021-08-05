# 210726 solved
def solution(n, k):
    queue = [i for i in range(1, n+1)]
    answer = []
    kCount = 1
    while(len(queue) > 0):
        if kCount%k == 0:
            answer.append(queue[0])
            del(queue[0])
        else:
            queue.append(queue[0])
            del(queue[0])
        kCount += 1
    return answer
    
    

n, k = map(int, input().split())
answer = solution(n, k)
answer = list(map(str, answer))
