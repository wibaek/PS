# 210726 solved
import sys
input = sys.stdin.readline

def solution(n):
    array = [int(input()) for _ in range(n)]
    array.sort()
    for i in array:
        print(i)
    
solution(int(input()))