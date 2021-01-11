def check(aaa):
    a = aaa[0]
    ha = list()
    for x in aaa:
        if x == a:
            continue
        if x != a:
            ha.append(a)
            if (x in ha):
                return False
            else:
                a = x
    return True

time = int(input())

count = 0

for x in range(time):
    words = input()
    if check(words) == True:
        count += 1

print(count)
