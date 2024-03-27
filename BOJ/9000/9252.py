# 2024 - 03 - 27
s1 = input()
s2 = input()

cache = [[0 for _ in range(len(s2) + 1)] for _ in range(len(s1) + 1)]

for i in range(1, len(s1) + 1):
    for j in range(1, len(s2) + 1):
        if s1[i - 1] == s2[j - 1]:
            cache[i][j] = cache[i - 1][j - 1] + 1
        else:
            cache[i][j] = max(cache[i - 1][j], cache[i][j - 1])

print(cache[-1][-1])
if cache[-1][-1] != 0:
    i = len(s1)
    j = len(s2)
    result = ""
    while i > 0 and j > 0:
        if cache[i][j] == cache[i - 1][j]:
            i -= 1
        elif cache[i][j] == cache[i][j - 1]:
            j -= 1
        else:
            result = s1[i - 1] + result
            i -= 1
            j -= 1
    print(result)
