#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, r1, r2, delta;
    scanf("%f %f %f", &a, &b, &c);
    delta = (pow(b,2))-4*a*c;
    if (delta<0 || a==0) {
        printf("Impossivel calcular\n");
    } else {
        r1 = (-b+pow(delta,1.0/2))/(2*a);
        r2 = (-b-pow(delta,1.0/2))/(2*a);
        printf("R1 = %.5f\n", r1);
        printf("R2 = %.5f\n", r2);
    }
    return 0;
}
