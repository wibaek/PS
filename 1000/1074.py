def solution():
    N, r, c = map(int,input().split())
    record = []
    answer = 0
    for i in range(N):
        record.append({
            'row' : 0 if r - sum([record[j]['row'] * (2 ** (N - j - 1)) for j in range(i)]) < 2 ** (N - i - 1) else 1,
            'column' : 0 if c - sum([record[j]['column'] * (2 ** ( N - j - 1)) for j in range(i)]) < 2 ** (N - i - 1) else 1
        })
    for i in range(N):
        answer += (2 * record[i]['row'] + record[i]['column']) * 2 ** ( 2 * (N - i - 1))
    print(answer)

solution()