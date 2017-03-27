#include <bits/stdc++.h>

int main () {
    int a, b, q, r;
    scanf("%d%d", &a, &b);
    if (b == 0) q = 0, r = 0;
    else q = a / b, r = a % b;
    while (r < 0) {
        if (b < 0) r -= b, q += 1;
        if (b > 0) r += b, q -= 1;
    }
    printf("%d %d\n", q, r);
    return 0;
}
