#include <bits/stdc++.h>

int main () {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                int k;
                scanf("%d", &k);
                int m[k];
                double sum = 0;
                int acima = 0;
                for (int j = 0; j < k; j++) scanf("%d", &m[j]), sum += m[j];
                sum /= k;
                for (int j = 0; j < k; j++) if (m[j] > sum) acima++;
                double k2 = k;
                double p = acima*100/k2;
                printf("%.3f%%\n", p);
        }
        return 0;
}
