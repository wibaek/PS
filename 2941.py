answer = 0
get = input()
otherCount = 0

checkC = 0
checkD = 0
checkDz = 0
checkL = 0
checkN = 0
checkS = 0
checkZ = 0

for x in list(get):
    if checkC:
        if x == '=' or '-':
            answer += 1
            otherCount -= 1
        checkC = 0
    if checkDz:
        if x == '=':
            answer += 2
            otherCount -= 1
        checkDz = 0
        checkD = 0
    if checkD:
        if x == '-':
            answer += 1
            otherCount -= 1
        elif x == 'z':
            checkDz = 1
        checkD = 0
    if checkL:
        if x == 'j':
            answer += 1
        checkL = 0
    if checkN:
        if x == 'j':
            answer += 1
        checkN = 0
    if checkS:
        if x == '=':
            answer += 1
            otherCount -= 1
        checkS = 0
    if checkZ:
        if x == '=':
            answer += 1
            otherCount -= 1
        checkZ = 0
    

    if x == 'c':
        checkC = 1
    elif x == 'd':
        checkD = 1
    elif x == 'l':
        checkL = 1
    elif x == 'n':
        checkN = 1
    elif x == 's':
        checkS = 1
    elif x == 'z':
        checkZ = 1
    elif x == '-':
        otherCount += 1
    elif x == '=':
        otherCount += 1

#     print(answer, otherCount)

# print(len(get))
# print(answer)
# print(otherCount)

print(len(get) - answer - otherCount)

    