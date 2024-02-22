def solution():
    N = int(input())
    table = []
    for i in range(N):
        table.append(input())
    table = list(set(table))

    table.sort(key = lambda x : (len(x), x))
    
    for element in table:
        print(element)
    
solution()