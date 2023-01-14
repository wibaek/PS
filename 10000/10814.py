def solution():
    n = int(input())
    table = list()
    for i in range(n):
        age, name = input().split()
        table.append({
            'age' : int(age),
            'name' : name,
            'pk' : i
        })
    
    table.sort(key = lambda x : (x['age'], x['pk']))

    for i in table:
        print(i['age'], i['name'])

solution()