#include <bits/stdc++.h>
using namespace std;

int n, ni, ci, num, den;

int main () {
    while (scanf("%d", &n) != EOF) {
        num = 0; den = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &ni, &ci);
            num += ni*ci;
            den += ci*100;
        }
        printf("%.4Lf\n", (long double) num/den);
    }
    return 0;
}
