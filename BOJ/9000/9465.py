import sys
input = sys.stdin.readline

def solution():
  # 입력
  N = int(input())
  board = []
  dp = [[-1 for _ in range(N)] for _ in range(2)]
  for _ in range(2):
    board.append(list(map(int,input().split())))
  # 구현
  # 1행은 그 자체가 가능한 최대값
  dp[0][0] = board[0][0]
  dp[1][0] = board[1][0]
  # 2행은 대각선으로 있는 2개를 포함한것이 최대값
  if N >= 2:
    dp[0][1] = dp[1][0] + board[0][1]
    dp[1][1] = dp[0][0] + board[1][1]
  # 3행 이상일시 대각선, 2칸 멀리 떨어진것(0, 1행)을 고려
  if N >= 3 :
    for i in range(2, N):
      for j in range(2):
        dp[j][i] = max(dp[0 if j == 1 else 1][i-1], dp[0][i-2], dp[1][i-2]) + board[j][i]
  # 출력
  print(max(dp[0][N-1], dp[1][N-1]))

T = int(input())
for _ in range(T):
  solution()