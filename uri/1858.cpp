#include <bits/stdc++.h>

int main () {
        int k;
        scanf("%d", &k);
        int min = 21;
        int imin;
        for (int i = 1; i <= k; i++) {
                int t;
                scanf("%d", &t);
                if (t < min) min = t, imin = i;
        }
        printf("%d\n", imin);
        return 0;
}
