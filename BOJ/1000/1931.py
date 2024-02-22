# 210730 solved
def solution():
    n = int(input())
    meetings = []
    for i in range(n):
        meetings.append(list(map(int, input().split())))
    meetings.sort(key = lambda x : (-x[0], -x[1]))
    currentStart = 2**31
    meetingCount = 0
    for meeting in meetings:
        if meeting[1] <= currentStart:
            meetingCount += 1
            currentStart = meeting[0]
    print(meetingCount)
        
solution()