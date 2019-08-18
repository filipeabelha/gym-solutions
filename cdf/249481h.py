def solve (n, x, y, k, h):
    return (k*x*n + k*y*n*(n-1)/2 >= h)

a = raw_input().split()

x = int(a[0])
k = int(a[1])
y = int(a[2])
h = int(a[3])

l = 0
r = 1000000000000000000000000

while (l < r):
    m = (l+r+1)/2
    if (solve(m, x, y, k, h)):
        r = m-1
    else:
        l = m

n = l
ans = n*k
h -= k*x*n + k*y*n*(n-1)/2

while (h > 0):
    ans += 1
    h -= x+n*y

print ans
