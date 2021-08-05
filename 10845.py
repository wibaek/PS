# solved 210727
import sys
input = sys.stdin.readline

def solution():
    N = int(input())
    queue = []
    for i in range(N):
        get = input().split()
        if get[0] == "push":
            queue.append(int(get[1]))
        elif get[0] == "pop":
            if len(queue) == 0:
                print(-1)
            else:
                print(queue[0])
                del(queue[0])
        elif get[0] == "size":
            print(len(queue))
        elif get[0] == "empty":
            print(1 if len(queue) == 0 else 0)
        elif get[0] == "front":
            print(-1 if len(queue) == 0 else queue[0])
        elif get[0] == "back":
            print(-1 if len(queue) == 0 else queue[len(queue)-1])
            
solution()