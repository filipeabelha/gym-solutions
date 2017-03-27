#include <bits/stdc++.h>

int main () {
    int n;
    while(scanf("%d", &n) != EOF) {
        int max = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (x > max) max = x;
        }
        if (max >= 20) printf("3\n");
        else if (max >= 10) printf("2\n");
        else printf("1\n");
    }
    return 0;
}
