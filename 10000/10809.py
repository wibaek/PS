text = input()

test = 65+28 +4
dic = {}
for x in range(test,test + 26):
    dic[chr(x)] = -1

#print(dic)
for x in range(len(text)):
    if dic[text[x]] == -1:
        dic[text[x]] = x

for x in dic.values():
    print(x,end=" ")
# 나온답
# 1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1
# 실제답
# 1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
