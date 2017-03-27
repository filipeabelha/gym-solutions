#include <bits/stdc++.h>

int sum, n[50];

int fib(int n) {
        sum++;
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else {
                return fib(n-1) + fib(n-2);
        }
}

int main () {
        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
                scanf("%d", &n[i]);
        }
        for (int i = 0; i < k; i++) {
                sum = 0;
                printf("fib(%d) = %d calls = %d\n", n[i], sum - 1, fib(n[i]));
        }        
        return 0;
}
