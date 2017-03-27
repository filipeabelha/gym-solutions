#include <bits/stdc++.h>

int main () {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        int sus[1050];
        memset(sus, 0, sizeof(sus));
        int max = 0;
        int imax;
        for (int i = 1; i <= n; i++) {
            int num;
            scanf("%d", &num);
            sus[i] = num;
            if (num > max) {
                max = num;
                imax = i;
            }
        }
        int max2 = 0;
        int imax2;
        for (int i = 1; i <= n; i++) {
            if (sus[i] > max2 and imax != i) {
                max2 = sus[i];
                imax2 = i;
            }
        }
        printf("%d\n", imax2);
    }
    return 0;
}
