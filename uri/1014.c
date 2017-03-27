#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2, dist;
    scanf("%f%f %f%f", &x1, &y1, &x2, &y2);
    dist = pow((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1), 1.0/2);
    printf("%.4f\n", dist);
    return 0;
}
