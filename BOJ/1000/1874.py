# 210726 solved
import sys
input = sys.stdin.readline
def solution():
    answer = ["+"]
    stack = [1]
    n = int(input())
    problem = [int(input()) for _ in range(n)]
    stackN = 2
    problemN = 0
    while(True):
        if len(stack) == 0:
            stack.append(stackN)
            stackN += 1
            answer.append("+")
        if stack[len(stack)-1] == problem[problemN]:
            stack.pop()
            problemN += 1
            answer.append("-")
        elif stack[len(stack)-1] < problem[problemN]:
            stack.append(stackN)
            stackN += 1
            answer.append("+")
        elif stack[len(stack)-1] > problem[problemN]:
             print("NO")
             return 0
        if problemN == n:
            for i in answer:
                print(i)
            return 0
        
solution()