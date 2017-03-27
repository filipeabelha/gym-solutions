#include <bits/stdc++.h>

int main () {
        int x;
        scanf("%d", &x);
        int n[10];
        n[0] = x;
        for (int i = 1; i < 10; i++) {
                n[i] = 2 * n[i-1];
        };
        for (int i = 0; i < 10; i++) {
                printf("N[%d] = %d\n", i, n[i]);
        };
        return 0;
}
