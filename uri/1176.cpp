#include <bits/stdc++.h>

int n[70];

long long fib(int n) {
        long long f[70];
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i <= n; i++) f[i] = f[i-1] + f[i-2];
        return f[n];
}

int main () {
        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
                scanf("%d", &n[i]);
        }
        for (int i = 0; i < k; i++) {
                printf("Fib(%d) = %lld\n", n[i], fib(n[i]));
        }        
        return 0;
}
