n = int(input())
solutionList = list(map(int,input().split()))

solutionList.sort()

currentLow = 0
testLow = 0
currentHigh = n - 1
testHigh = n - 1
currentDiff = 20000000001

while testLow < testHigh:
    # print("One Cycle:", currentHigh,currentLow,testHigh,testLow,currentDiff)
    testDiff = solutionList[testHigh] + solutionList[testLow]
    if abs(testDiff) < abs(currentDiff):
        currentLow = testLow
        currentHigh = testHigh
        currentDiff = solutionList[currentHigh] + solutionList[currentLow]

    if testDiff >= 0:
        testHigh -= 1
    else:
        testLow += 1

print(solutionList[currentLow], solutionList[currentHigh])
