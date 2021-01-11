def func():
    inputted = input().split()
    n = int(inputted[0])
    text = inputted[1]

    for x in text:
        print(x*n,end="")
    print()






n = int(input())
for x in range(n):
    func()