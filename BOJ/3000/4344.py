def hey(n,scores):
    average = float(sum(scores))/n
    overAV = 0
    for x in range(n):
        if scores[x] > average:
            overAV += 1
    return (format((overAV / n),"5.3%"))

totaln = int(input())
for x in range(totaln):
    a = list(map(int,input().split()))
    print(hey(a[0],a[1:]))

