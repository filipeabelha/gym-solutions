#include <stdio.h>

int main() {
    int n, i;
    int x[10000], y[10000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (i = 0; i < n; i++) {
        if (y[i] == 0) {
            printf("divisao impossivel\n");
        } else {
            float res = x[i]/((y[i]*10)/10.0);
            printf("%.1f\n", res);
        }
    }
    return 0;
}
