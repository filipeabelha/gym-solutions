#include <stdio.h>

int main() {
    int n, i;
    float a[10000], b[10000], c[10000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%f %f %f", &a[i], &b[i], &c[i]);
    }
    for (i = 0; i < n; i++) {
        float m = (2*a[i] + 3*b[i] + 5*c[i])/10.0;
        printf("%.1f\n", m);
    }
    return 0;
}
