def solution():
  n = int(input())
  time = []
  for i in range(n):
    start, end = map(int,input().split())
    time.append([start, end, end - start])

  
  
solution()

