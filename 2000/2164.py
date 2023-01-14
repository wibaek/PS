# import queue
import collections

# def solution():
#     n = int(input())
#     cardStack = queue.Queue()
#     for i in range(1, n+1):
#         cardStack.put(i)
#     for i in range(n-1):
#         cardStack.get()
#         cardStack.put(cardStack.get())
#     print(cardStack.get())

def solution():
    n = int(input())
    cardStack = collections.deque()
    for i in range(1, n+1):
        cardStack.append(i)
    for i in range(n-1):
        cardStack.popleft()
        cardStack.append(cardStack.popleft())
    print(cardStack.popleft())

solution()