#include <bits/stdc++.h>
using namespace std;

int n, c, k, x, ans;

int main () {
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        if (i == 1) ans = n;
        if (k > x and i > 1) ans = n-i+1;
        x = k+c;
    }
    printf("%d\n", ans);
    return 0;
}
