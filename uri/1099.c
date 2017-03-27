#include <stdio.h>

int main() {
    int n, i, aux, ress;
    scanf("%d", &n);
    int x[10000], y[10000];
    for (i = 0; i < n; i++) {
        scanf("%d" "%d", &x[i], &y[i]);
    }
    for (i = 0; i < n; i++) {
        if (x[i] > y[i]) {
            aux = x[i];
            x[i] = y[i];
            y[i] = aux;
        }
        if (x[i] != y[i]) {
            if (x[i] % 2 == 0) x[i] = x[i] + 1; else x[i] = x[i] + 2;
            if (y[i] % 2 == 0) y[i] = y[i] - 1; else y[i] = y[i] - 2;
            int res = ((y[i]-x[i])/2)+1;
            ress = ((x[i] + y[i])*res)/2;
        } else ress = 0;
        printf("%d\n", ress);
    }
    return 0;
}
