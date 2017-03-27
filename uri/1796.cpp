#include <bits/stdc++.h>

int main () {
    int n, x = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        if (k) x++;
    }
    if (2*x < n) printf("Y\n");
    else printf("N\n");
    return 0;
}
