def solution():
	n, m = map(int, input().split())
	for i in range(1, n-m+1+1):
		req([i], m, n)

def req(queue, lengthMax, nMax):
	if len(queue) < lengthMax:
		for i in range(queue[-1]+1, nMax+1):
			newQueue = queue[:]
			newQueue.append(i)
			req(newQueue, lengthMax, nMax)
	else:
		print(" ".join(list(map(str, queue))))
    
solution()