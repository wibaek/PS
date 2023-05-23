s = input()

mobis = ["M", "O", "B", "I", "S"]
count = [False, False, False, False, False]

for c in s:
    if c in mobis:
        count[mobis.index(c)] = True

if False in count:
    print("NO")
else:
    print("YES")
