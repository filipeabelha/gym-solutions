#include <bits/stdc++.h>

int main () {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        int pa = 0, pb = 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d", &a);
            scanf("%d", &b);
            if (a > b) pa++;
            if (b > a) pb++;
        }
        printf("%d %d\n", pa, pb);
    }
    return 0;
}
