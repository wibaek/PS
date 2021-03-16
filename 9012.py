def solution():
    case = list(input())
    count = 0
    for i in case:
        if i == '(':
            count += 1
        elif i == ')':
            count -= 1
        if count < 0:
            return "NO"
    if count == 0:
        return "YES"
    else:
        return "NO"
        
def main():
    for _ in range(int(input())): print(solution())

main()