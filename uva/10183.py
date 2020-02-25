f = [0]*500
f[1] = 1
f[2] = 1
for i in range(2, 500):
    f[i] = f[i-1] + f[i-2]

def count (k):
    r = 0

    for i in range(1, 2):
        if (f[i] <= k):
            r += 1

    for i in range(3, 500):
        if (f[i] <= k):
            r += 1

    return r

while True:
    x, y = input().split()
    x = int(x)
    y = int(y)
    if (x == 0 and y == 0):
        break
    else:
        ans = count(y)
        if x > 1:
            ans -= count(x-1)

        print("{}".format(ans))
