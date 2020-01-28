n = input()
 
N = 5005
c = [0]*N
 
c[0] = 1
c[1] = 1
for i in range(2, N):
    c[i] = 2*(2*i-1)*c[i-1]/(i+1)
 
ans = 0
for i in range(n+1):
    ans = ans + c[i]*c[n-i]
 
print ans
