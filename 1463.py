def solution(n):
    board = [-1 for _ in range(MAX_VALUE + 1)]
    board[1] = 0
    lastTier = [1]
    newTier = []
    tier = 1
    while board[n] == -1:
        for i in lastTier:
            calc1 = i + 1
            calc2 = i * 2
            calc3 = i * 3
            if calc1 <= n:
                if board[calc1] == -1:
                    board[calc1] = tier
                    newTier.append(calc1)
            if calc2 <= n:
                if board[calc2] == -1:
                    board[calc2] = tier
                    newTier.append(calc2)
            if calc3 <= n:
                if board[calc3] == -1:
                    board[calc3] = tier
                    newTier.append(calc3)

        tier += 1
        lastTier = newTier.copy()
        newTier.clear()
    return board[n]
            
MAX_VALUE = 100 * 10000

print(solution(int(input())))