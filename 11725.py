import sys
input = sys.stdin.readline
sys.setrecursionlimit(100003)

def solution():
  V = int(input()) # 정점의 갯수
  global line, answer
  answer = [-1 for _ in range(V+1)]
  line = [[] for _ in range(V+1)] # 간선의 정보
  # 입력
  for _ in range(V-1):
    get = list(map(int,input().split()))
    line[get[0]].append(get[1])
    line[get[1]].append(get[0])
  # 검증
  dfs(1, 0)
  # 출력
  for i in range(2, V+1):
    print(answer[i])
  
# 구현
def dfs(node: int, beforeNode: int):
  global line, answer
  #if answer[node] != -1:
  #  return None
  answer[node] = beforeNode
  for targetNode in line[node]:
    if targetNode != beforeNode:
      dfs(targetNode, node)
  return None
  
solution()
