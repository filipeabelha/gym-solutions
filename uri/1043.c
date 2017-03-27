#include <stdio.h>

int main() {
    float a, b, c, area, per;
    scanf("%f %f %f", &a, &b, &c);
    if (a<b+c && b<c+a && c<a+b) {
        per = a+b+c;
        printf("Perimetro = %.1f\n", per);
    } else {
        area = ((a+b)*c)/2.0;
        printf("Area = %.1f\n", area);
    }
    return 0;
}
