#include <stdio.h>

int main() {
    float a, b, c, x;
    scanf("%f%f%f", &a, &b, &c);
    x = (2*a + 3*b + 5*c)/10;
    printf("MEDIA = %.1f\n", x);
    return 0;
}
