#include <bits/stdc++.h>

int main () {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                double k;
                scanf("%lf", &k);
                int count = 0;
                while (k > 1) k /= 2, count++;
                printf("%d dias\n", count);
        }
        return 0;
}
