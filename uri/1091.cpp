#include <bits/stdc++.h>

int main () {
    int n;
    while(1) {
        scanf("%d", &n);
        if (n == 0) break;
        int xd, yd;
        scanf("%d%d", &xd, &yd);
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x-xd == 0 or y-yd == 0) {
                printf("divisa\n");
                continue;
            }
            if (x-xd > 0 and y-yd > 0) {
                printf("NE\n");
                continue;
            }
            if (x-xd < 0 and y-yd < 0) {
                printf("SO\n");
                continue;
            }
            if (x-xd > 0 and y-yd < 0) {
                printf("SE\n");
                continue;
            }
            if (x-xd < 0 and y-yd > 0) {
                printf("NO\n");
                continue;
            }
        }
    }
    return 0;
}
