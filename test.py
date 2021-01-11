# a = 0
# b = 0
# c=7680
# while(1):
#     a = int(input())
#     b = int(input())
#     d = (a+b)/2
#     print(d)
#     print(d-c)

# while(1):
#     a = int(input())
#     print(a-c)
# d = 0.004
# A = 0.018
# V = 0
# while(1):
#     dm = float(input())
#     V += 1000
#     F = 9.8 * dm
#     print("F is",F)
#     ff = ((8.85 * 10**-12 )* A * V * V * 0.5 )/(d * d)
#     print("F0 is",ff)
#     percent = ((F - ff)/ff) * 100
#     print("per is",percent)


# ////////////////////////////////////////////////////////////
# a = 0
# for x in range(2,10,2):
#     i = float(input("I: "))
#     print(float(x) / i)
#     a += float(x) / i
# print(a/4)

# L = 0.01  # 도선길이
# g = [0.03,0.06,0.09,0.13,0.14]  # 질량
# I = 4
# B = [0.0079,0.0151,0.0225,0.0295,0.0327]
#
# N1 = 0  # 측정 무게
# N2 = 0  # 계산된 자기력
# N3 = 0  # 차이
# PER = 0  # 비율 차이ㅏ/계산값 N2/N3
#
# for x in range(5):
#     print(x+1,"번째------------")
#     N1 = (g[x] * 9.8 )/1000
#     N2 = I * L* B[x]
#     N3 = N1 - N2
#     print("측정 무게: ",N1)
#     print("계산된 자기력",N2)
#     print("차이",N3)
#     print("비율",N3/N2)
#

I = 4.6137339700286132421108756819846876060911229386037040248887072698

N2 = 800
r2 = 0.0195
i = [0.05,0.10,0.15,0.20,0.25]

cal = [0.0734,0.1390,0.2090,0.2700,0.3550]

for x in range(5):
    calced = I * N2 * r2 * r2 * i[x]
    print("계산값: ",calced)
    print("오차: ",(calced-cal[x])/calced)