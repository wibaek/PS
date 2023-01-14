# 210729 solved
def solution(a, b):
    if a < b:
        a, b = b, a
    return g(a, b)
    
def g(p, q):
    if q == 0:
        return p
    return g(q, p%q)
    
a, b = map(int, input().split())
gcd = solution(a, b)
print(gcd)
print(int(a*b/gcd))