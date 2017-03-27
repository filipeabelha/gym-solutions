#include <bits/stdc++.h>

int main () {
    long long n;
    scanf("%lld", &n);
    while (n > 0) {
        int k = n % 10;
        n -= k;
        n /= 10;
        printf("%d", k);
    }
    printf("\n");
    return 0;
}
