#include <bits/stdc++.h>

int k[105];

int main () {
    int n, d;
    while (1) {
        scanf("%d %d", &n, &d);
        if (n == 0 and d == 0) break;
        for (int i = 0; i < 103; i++) k[i] = 1;
        for (int i = 0; i < d; i++) for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            k[j] *= x;
        }
        bool yes = false;
        for (int i = 0; i < n; i++) if (k[i] == 1) yes = true;
        if (yes) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
