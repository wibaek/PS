a = input().upper()

word = dict()
ASCHISTART = 65
ASLENGHT = 26


for x in range(ASCHISTART,ASCHISTART+ASLENGHT):
    word[chr(x)] = 0


for x in a:
    word[x] += 1

biggest = 0
for x in word.values():
    if x > biggest:
        biggest = x

count = 0

for x in word.values():
    if (x==biggest):
        count += 1

if (count>= 2):
    print("?")
else:
    b = list(word.items())
    # print(b)
    for x in b:
        if x[1] == biggest:
            print(x[0])