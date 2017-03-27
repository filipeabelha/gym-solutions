#include <bits/stdc++.h>

int main () {
        double n[100];
        scanf("%lf", &n[0]);
        for (int i = 1; i < 100; i++) {
                n[i] = n[i-1]/2;
        };
        for (int i = 0; i < 100; i++) {
                printf("N[%d] = %.4lf\n", i, n[i]);
        };
        return 0;
}
