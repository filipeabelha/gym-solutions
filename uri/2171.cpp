#include <bits/stdc++.h>
using namespace std;

int n, a, b, ansa, ansb;

int main () {
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        a = b = ansa = ansb = 0;
        for (int i = 1; n > 0; i++) {
            a = i; b = 1;
            if (n >= (a+b)) {
                n -= (a+b);
                ansa += a;
                ansb += b;
            } else {
                ansa += a;
                n -= a;
                if (n < 0) ansb += n;
            }
        }
        printf("%d %d\n", ansa, ansb);
    }
    return 0;
}
