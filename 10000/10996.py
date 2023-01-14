n = int(input())

if n ==1:
    print("*")
else:
    for x in range(n):

        for y in range(n):
            if y%2 == 0:
                if y == 0:
                    print("*",end="")
                else:
                    print(" *",end="")

        print("")

        for z in range(n):
            if z%2 == 1:
                print(" *",end="")
        print("")
