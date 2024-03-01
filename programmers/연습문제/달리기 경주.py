class Node:
    def __init__(self, value, prev=None, next=None):
        self.value = value
        self.prev = prev
        self.next = next


def swapNode(node):
    prevNode = node.prev
    if prevNode.prev is not None:
        prevNode.prev.next = node
    if node.next is not None:
        node.next.prev = prevNode
    prevNode.next = node.next
    node.prev = prevNode.prev
    node.next = prevNode
    prevNode.prev = node


def solution(players, callings):
    hashMap = dict()

    prevNode = None
    for p in players:
        hashMap[p] = Node(p, prevNode)
        if prevNode != None:
            prevNode.next = hashMap[p]
        prevNode = hashMap[p]

    for c in callings:
        swapNode(hashMap[c])

    cur = hashMap[players[0]]
    while cur.prev != None:
        cur = cur.prev

    answer = []
    answer.append(cur.value)
    while cur.next != None:
        cur = cur.next
        answer.append(cur.value)

    return answer
