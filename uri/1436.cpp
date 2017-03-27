#include <bits/stdc++.h>

int main () {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                int k;
                scanf("%d", &k);
                int m[k];
                for (int j = 0; j < k; j++) {
                        scanf("%d", &m[j]);
                }
                printf("Case %d: %d\n", i+1, m[k/2]);
        }
        return 0;
}
