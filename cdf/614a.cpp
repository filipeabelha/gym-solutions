#include <bits/stdc++.h>
#define ll long long

int main () {
    ll l, r, k, x = 1;
    int printed = 0;
    scanf("%I64d%I64d%I64d", &l, &r, &k);
    while (1) {
        if (x >= l) printf("%I64d ", x), printed = 1;
        if (x > r/k) break;
        x *= k;
    }
    if (!printed) printf("-1 ");
    printf("\n");
    return 0;
}
