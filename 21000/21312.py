def solution():
  num = list(map(int, input().split()))
  num.append(num[0]*num[1])
  num.append(num[2]*num[1])
  num.append(num[0]*num[2])
  num.append(num[0]*num[1]*num[2])
  even = []
  odd = []
  for i in num:
    if i%2 == 0:
      even.append(i)
    else:
      odd.append(i)
  even.sort()
  odd.sort()
  if len(odd) == 0:
    print(even[-1])
  else:
    print(odd[-1])

solution()