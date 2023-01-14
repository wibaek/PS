def solution():
	n, m = map(int, input().split())
	nList = list(map(int, input().split()))
	nList.sort()
	nList.insert(0, -1)
	for i in range(1, n-m+1+1):
		req([i], m, n, nList)

def req(queue, lengthMax, nMax, nList):
	if len(queue) < lengthMax:
		for i in range(queue[-1]+1, nMax+1):
			newQueue = queue[:]
			newQueue.append(i)
			req(newQueue, lengthMax, nMax)
	else:
		transQueue = []
		for i in queue:
			transQueue.append(nList[i])
		print(" ".join(list(map(str, transQueue))))
    
solution()