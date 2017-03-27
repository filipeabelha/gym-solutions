#include <bits/stdc++.h>

int main () {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                int k;
                scanf("%d", &k);
                long long r = pow(2, k) / 12000;
                printf("%lld kg\n", r);
        }
        return 0;
}
