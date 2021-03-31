def solution(n, k):
    board = [-1 for _ in range(MAX_VALUE + 1)]
    board[n] = 0
    lastTier = [n]
    newTier = []
    tier = 1
    while board[k] == -1:
        for i in lastTier:
            calc1 = i + 1
            calc2 = i - 1
            calc3 = i * 2
            if calc1 <= MAX_VALUE:
                if board[calc1] == -1:
                    board[calc1] = tier
                    newTier.append(calc1)
            if 0 <= calc2 <= MAX_VALUE:
                if board[calc2] == -1:
                    board[calc2] = tier
                    newTier.append(calc2)
            if 0 <= calc3 <= MAX_VALUE:
                if board[calc3] == -1:
                    board[calc3] = tier
                    newTier.append(calc3)

        tier += 1
        lastTier = newTier.copy()
        newTier.clear()
    return board[k]

MAX_VALUE = 110001

n, k = map(int,input().split())
print(solution(n, k))