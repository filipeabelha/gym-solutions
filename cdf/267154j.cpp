#include <bits/stdc++.h>
using namespace std;

int n, x, ans;

int main () {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        if (x == 0) ans += 32;
        if (x == 1) ans += 16;
        if (x == 2) ans += 8;
        if (x == 4) ans += 4;
        if (x == 8) ans += 2;
        if (x == 16) ans += 1;
    }
    printf("%5Lf\n", (long double) ans/16.);

}
