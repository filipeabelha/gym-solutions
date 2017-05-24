#include <bits/stdc++.h>
using namespace std;

int n, m, xa, ya, xb, yb, inp;

int main () {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int x = 1; x <= n; x++) for (int y = 1; y <= m; y++) {
            scanf("%d", &inp);
            if (inp == 1) xa = x, ya = y;
            if (inp == 2) xb = x, yb = y;
        }
        printf("%d\n", abs(xa-xb)+abs(ya-yb));
    }
    return 0;
}
