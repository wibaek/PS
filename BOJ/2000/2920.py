get = input().split()
new = []

for x in get:
    new.append(x)

get.sort()
if new == get:
    print("ascending")
else:
    get.sort(reverse=True)
    if new == get:
        print("descending")
    else:
        print("mixed")