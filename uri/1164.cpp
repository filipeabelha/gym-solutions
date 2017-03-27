#include <bits/stdc++.h>

int main () {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int k;
            scanf("%d", &k);
            int sum = 0;
            for (int j = 1; j < k; j++) if (k % j == 0) sum += j;
            if (sum == k) printf("%d eh perfeito\n", k); else printf("%d nao eh perfeito\n", k);
        };
        return 0;
}
