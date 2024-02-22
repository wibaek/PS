n = 0
number = input()
origin = number
if int(number)<10:
    origin = '0' + number

if int(number) < 10:
    number = '0' + number

a = number[1]
b = (int(number[0]) + int(number[1])) % 10

number = str(a) + str(b)
n += 1
#print(number)


while(number!=origin):
    if int(number)<10:
        number = '0' + str(int(number))

    a = number[1]
    b = (int(number[0]) + int(number[1]))%10

    number = str(a) + str(b)
    n+=1
    #print(number)


print(n)