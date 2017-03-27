#include <bits/stdc++.h>

int main () {
        int n[1000];
        int x;
        scanf("%d", &x);
        for (int i = 0; i < 1000; i++) {
                n[i] = i % x;
        };
        for (int i = 0; i < 1000; i++) {
                printf("N[%d] = %d\n", i, n[i]);
        };
        return 0;
}
