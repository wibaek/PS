while True:
    get = input()
    if get == ".":
        break
    stack = []
    for i in get:
        if i == "(" or i == "[":
            stack.append(i)
        elif i == ")":
            if stack != []:
                if stack[-1] == "(":
                    stack.pop()
                else:
                    print("no")
                    break
            else:
                print("no")
                break
        elif i == "]":
            if stack != []:
                if stack[-1] == "[":
                    stack.pop()
                else:
                    print("no")
                    break
            else:
                print("no")
                break
        elif i == ".":
            if stack == []:
                print("yes")
            else:
                print("no")
        else:
            continue
