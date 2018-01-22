ans = 1

def gcd (a, b):
    if b > 0:
        return gcd(b, a%b)
    return a

def lcm (a, b):
    return a*b/gcd(a,b)

n = input()
for i in range(2, n+1):
    ans = lcm(ans, i)

print ans
