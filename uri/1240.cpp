#include <bits/stdc++.h>

int main () {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                long long a, b;
                scanf("%lld%lld", &a, &b);
                int j;
                for (j = 0; j < 14; j++) if (b / pow(10, j) < 1) break;
                long long powe = pow(10, j);
                if ((a - b) % powe == 0) printf("encaixa\n"); else printf("nao encaixa\n");
        }
        return 0;
}
