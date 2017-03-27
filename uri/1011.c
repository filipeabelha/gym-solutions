#include <stdio.h>

int main() {
    int r;
    scanf("%d", &r);
    double x = (4.0/3) * 3.14159 * r * r * r;
    printf("VOLUME = %.3f\n", x);
    return 0;
}
