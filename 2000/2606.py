class Computer:
    def __init__(self, computerId):
        self.related = []
        self.computerId = computerId

    def addRelated(self, i):
        self.related.append(i)


checked = []


def check(computer):
    if computer.computerId in checked:
        return
    else:
        checked.append(computer.computerId)
        for i in computer.related:
            check(computers[i])


def solution():
    global computers
    computers = list()

    computerCount = int(input())
    relatedCount = int(input())

    for i in range(computerCount + 1):
        computers.append(Computer(i))

    for i in range(relatedCount):
        a, b = map(int, input().split())
        computers[a].addRelated(b)
        computers[b].addRelated(a)

    check(computers[1])

    print(len(checked) - 1)


solution()
