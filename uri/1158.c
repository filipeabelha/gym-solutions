#include <stdio.h>

int main() {
    int i, j, n, x, y;
    scanf("%d", &n);
    int sum[10000];
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        if (x % 2 == 0) x++;
        for (j = 0; j < y; j++) {
            sum[i] = sum[i] + x + 2*j;
        }
    };
    for (i = 1; i <= n; i++) {
        printf("%d\n", sum[i]);
    };
    return 0;
}
