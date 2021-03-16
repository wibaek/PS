import sys

def solution():
    n = int(input())
    stack = list()
    order = [sys.stdin.readline() for i in range(n)]
    for i in order:
        if i == 'top\n':
            print(-1 if len(stack) == 0 else stack[-1])
        elif i == 'pop\n':
            if len(stack) == 0:
                print(-1)
            else:
                print(stack.pop())
        elif i == 'size\n':
            print(len(stack))
        elif i == 'empty\n':
            print(1 if len(stack) == 0 else 0)
        else:
            x = int(i.split()[1])
            stack.append(x)

solution()