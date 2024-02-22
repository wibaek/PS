def solution(k):
    if k <= 20:
        move_history = []
        print(tower_history(k, 1, 3, 2, move_history))
        for move in move_history:
            print(move[0], move[1])
    else:
        # print(tower(k, 1, 3, 2))
        print(2 ** k - 1)


# def tower(n, fr, to, spare):
#     if n == 1:
#         return 1
#     else:
#         return tower(n-1, fr, spare, to) + tower(1, fr, to, spare) + tower(n-1, spare, to, fr)


def tower_history(n, fr, to, spare, move_history):
    if n == 1:
        move_history.append([fr, to])
        return 1
    else:
        return tower_history(n-1, fr, spare, to, move_history) + tower_history(1, fr, to, spare, move_history) + tower_history(n-1, spare, to, fr, move_history)


solution(int(input()))
