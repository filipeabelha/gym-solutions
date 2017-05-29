#include <bits/stdc++.h>
using namespace std;

int n, q;
double a, b;

int main () {
    while (1) {
        scanf("%d", &n); if (!n) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d%lf%lf", &q, &a, &b);
            printf("Size #%d:\nIce Cream Used: %.2lf cm2\n", i, 2.5*q*(a+b));
        }
        printf("\n");
    }
    return 0;
}
