import sys
input = sys.stdin.readline
sys.setrecursionlimit(100003)

def solution():
  V = int(input()) # 정점의 갯수
  global line
  line = [[] for _ in range(V+1)]
  firstCache = [-1 for _ in range(V+1)]
  secondCache = [-1 for _ in range(V+1)]
  # 입력
  for _ in range(V-1):
    get = list(map(int,input().split()))
    line[get[0]].append((get[1], get[2]))
    line[get[1]].append((get[0], get[2]))
  # 검증
  firstBiggest = dfs(1, firstCache, 0) # firstCache에 임의의 노드(1)로 부터의 각각 거리 구하기
  endNode = firstCache.index(firstBiggest) # 지름의 한 끝점 찾기
  radius = dfs(endNode, secondCache, 0)
  print(radius)
  
# 구현
def dfs(node: int, cache: list, beforeNodeLength: int) -> int:
  global line
  if cache[node] != -1:
    return cache[node]
  cache[node] = beforeNodeLength
  ret = beforeNodeLength
  for targetNode, nodeLength in line[node]:
    ret = max(ret, dfs(targetNode, cache, beforeNodeLength + nodeLength))
  return ret
  
solution()
