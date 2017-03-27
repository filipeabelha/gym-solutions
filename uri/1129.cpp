#include <bits/stdc++.h>

int main () {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        for (int j = 0; j < n; j++) {
            int x, r = -1, null = 0;
            for (int i = 0; i < 5; i++) {
                scanf("%d", &x);
                if (x <= 127) {
                    if (r >= 0) null = 1;
                    r = i;
                }
            }
            if (null or r == -1) printf("*\n");
            else if (r == 0) printf("A\n");
            else if (r == 1) printf("B\n");
            else if (r == 2) printf("C\n");
            else if (r == 3) printf("D\n");
            else if (r == 4) printf("E\n");
        }
    }
    return 0;
}

