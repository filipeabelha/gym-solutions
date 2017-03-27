#include <bits/stdc++.h>

int main () {
    int t;
    scanf("%d", &t);
    char chr;
    for (int i = 0; i < t; i++) {
        char names[105][55];
        double presence[105];
        double total[105];
        memset(presence, 0, sizeof(presence));
        memset(total, 0, sizeof(total));
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
            scanf("%s", names[j]);
        scanf("%c", &chr);
        int nameindex = 0;
        while (1) {
            scanf("%c", &chr);
            if (chr == 32) {
                nameindex++;
                continue;
            }
            if (chr == 10)
                break;
            if (chr == 'A')
                total[nameindex]++;
            else if (chr == 'P')
                total[nameindex]++, presence[nameindex]++;
        }
        int space = 0;
        for (int j = 0; j < n; j++) {
            presence[j] /= total[j];
            if (presence[j] < 0.75) {
                if (space) printf(" ");
                printf("%s", names[j]);
                space = 1;
            }
        }
        printf("\n");
    }
    return 0;
}
