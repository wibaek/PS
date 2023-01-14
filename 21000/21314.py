def solution():
  minsu = input()
  # biggest
  bigList = []
  n = len(minsu)
  pointer = 0
  stack = 0
  while(pointer<n):
    if minsu[pointer] == 'M':
      if 'K' in minsu[pointer:]:
        stack += 1
      else:
        bigList.append('1')
    else:
      bigList.append(str(5*(10**stack)))
      stack = 0
    
    pointer += 1
  print("".join(bigList))
  # smallest
  smallList = []
  for i in list(minsu):
    if i == 'M':
      if len(smallList) == 0:
        smallList.append('1')
      else:
        if smallList[-1] == '5':
          smallList.append('1')
        else:
          smallList.append('0')
    else:
      smallList.append('5')
  print("".join(smallList))
      
solution()