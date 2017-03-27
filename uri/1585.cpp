#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b, res;
        scanf("%d%d", &a, &b);
        res = a*b/2;
        printf("%d cm2\n", res);
    }
    return 0;
}
