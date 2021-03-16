def solution():
    h, w, n = map(int,input().split()) # 층수, 방수, n번쨰 손님
    answerH = (n - 1) % h + 1
    answerW = (n - 1) // h + 1
    print(str(answerH) + (str(answerW) if answerW > 9 else ('0'+ str(answerW))))

def main():
    t = int(input())
    for _ in range(t): solution()

main()