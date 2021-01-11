def func(text):
    score = 0
    nowscore = 0
    for x in text:
        if x == 'O':
            nowscore += 1
            score += nowscore

        elif x == 'X':
            nowscore = 0
    return score

n = int(input())

for x in range(n):
    a = input()
    print(func(a))
