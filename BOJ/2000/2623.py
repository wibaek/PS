# 2024 - 03 - 24

singer_count, pd_count = map(int, input().split())

singers = [
    {
        "value": i,
        "required": [],
        "required_by": [],
        "done": False,
    }
    for i in range(singer_count + 1)
]
for i in range(pd_count):
    inp = list(map(int, input().split()))

    prev = inp[1]
    for j in inp[2:]:
        singers[j]["required"].append(prev)
        singers[prev]["required_by"].append(j)
        prev = j


answer = []
answer_count = 0

prev_answer_count = 0
while answer_count < singer_count:
    for i in range(1, singer_count + 1):
        if not singers[i]["done"] and len(singers[i]["required"]) == 0:
            answer.append(i)
            answer_count += 1
            singers[i]["done"] = True
            for j in singers[i]["required_by"]:
                singers[j]["required"].remove(i)
    if prev_answer_count == answer_count:
        print(0)
        break
    prev_answer_count = answer_count

for i in answer:
    print(i)
