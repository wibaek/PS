# 2024-02-22
def solution(friends, gifts):
    convert = {}
    index = 0
    friends_count = len(friends)
    for p in friends:
        convert[p] = index
        index += 1
    table = [[0 for i in range(friends_count)] for i in range(friends_count)]
    for g in gifts:
        names = g.split()
        sender = convert[names[0]]
        receiver = convert[names[1]]
        table[sender][receiver] += 1

    gift_index = [0 for i in range(friends_count)]
    for i in range(friends_count):
        for j in range(friends_count):
            gift_index[i] += table[i][j]
            gift_index[j] -= table[i][j]

    gift_count = [0 for i in range(friends_count)]
    for i in range(friends_count):
        for j in range(i + 1, friends_count):
            if table[i][j] > table[j][i]:
                gift_count[i] += 1
            elif table[i][j] < table[j][i]:
                gift_count[j] += 1
            else:
                if gift_index[i] > gift_index[j]:
                    gift_count[i] += 1
                elif gift_index[i] < gift_index[j]:
                    gift_count[j] += 1

    answer = max(gift_count)
    return answer
