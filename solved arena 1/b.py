index = 0
word_record = []

n = int(input())
for i in range(n):
    a = input()
    word_record.append(a)
    if a == "?":
        index = i

if index == 0:
    start = ""
else:
    start = word_record[index - 1][-1]

if index == n - 1:
    end = ""
else:
    end = word_record[index + 1][0]


n = int(input())
for i in range(n):
    a = input()
    if a in word_record:
        continue

    if start != "":
        if a[0] != start:
            continue

    if end != "":
        if a[-1] != end:
            continue
    print(a)
