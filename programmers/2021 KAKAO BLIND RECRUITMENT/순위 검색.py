# 2025.02.17
import bisect


def exec(raw_query, db):
    query = raw_query.split()

    if query[0] == "-":
        pointer1 = [db["java"], db["python"], db["cpp"]]
    else:
        pointer1 = [db[query[0]]]

    pointer2 = []
    if query[2] == "-":
        for p1 in pointer1:
            pointer2.extend([p1["frontend"], p1["backend"]])
    else:
        for p1 in pointer1:
            pointer2.append(p1[query[2]])

    pointer3 = []
    if query[4] == "-":
        for p2 in pointer2:
            pointer3.extend([p2["junior"], p2["senior"]])
    else:
        for p2 in pointer2:
            pointer3.append(p2[query[4]])

    pointer4 = []
    if query[6] == "-":
        for p3 in pointer3:
            pointer4.extend([p3["chicken"], p3["pizza"]])
    else:
        for p3 in pointer3:
            pointer4.append(p3[query[6]])

    score = int(query[7])

    count = 0
    for p in pointer4:
        # 이진탐색 안하고 linear하게 하면 시간 초과
        idx = bisect.bisect_left(p, score)
        count += len(p) - idx

    return count


def solution(info, query):
    answer = []

    db = {"java": {}, "python": {}, "cpp": {}}
    for key in db.values():
        key["backend"] = {}
        key["frontend"] = {}

    for key in db.values():
        for key2 in key.values():
            key2["junior"] = {}
            key2["senior"] = {}

    for key in db.values():
        for key2 in key.values():
            for key3 in key2.values():
                key3["pizza"] = []
                key3["chicken"] = []

    for i in info:
        data = i.split()
        db[data[0]][data[1]][data[2]][data[3]].append(int(data[4]))

    for key in db.values():
        for key2 in key.values():
            for key3 in key2.values():
                key3["pizza"].sort()
                key3["chicken"].sort()

    answer = []
    for q in query:
        answer.append(exec(q, db))

    return answer


"""
가능한 조건의 개수
3 * 2 * 2 * 2 * 100_000 = 2_400_000
or 24 + a
4 * 3 * 3 * 3 = 108개... 어렵진 않음
"""
