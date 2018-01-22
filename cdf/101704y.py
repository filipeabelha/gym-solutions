f = [0] * 1010
f[0] = 0
f[1] = f[2] = 1
for i in range(3, len(f)):
    f[i] = f[i-1] + f[i-3]
a = input()
print f[a]
