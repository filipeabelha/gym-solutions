#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 2; i <= n; i = i+2) {
        printf("%d^2 = %.0f\n", i, pow(i, 2));
    }
    return 0;
}
