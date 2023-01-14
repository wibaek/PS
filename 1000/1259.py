def check(a):
    if a == a[::-1]:
        print("yes")
    else:
        print("no")


while(1):
    get = input()
    if get == '0':
        break
    check(get)
