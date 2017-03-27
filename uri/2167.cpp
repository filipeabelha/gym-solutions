#include <bits/stdc++.h>

int n, a, b, ok;

int main () {
    scanf("%d%d", &n, &b);
    for (int i = 2; i <= n; i++) {
        a = b;
        scanf("%d", &b);
        if (b < a) {
            printf("%d\n", i);
            ok = 1;
            break;
        }
    }
    if (!ok) printf("0\n");
    return 0;
}
