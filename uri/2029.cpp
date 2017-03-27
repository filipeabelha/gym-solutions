#include <bits/stdc++.h>

int main () {
    double v, d;
    while(scanf("%lf%lf", &v, &d) != EOF) {
        double a = 3.14*d*d/4;
        double h = v / a;
        printf("ALTURA = %.2lf\nAREA = %.2lf\n", h, a);
    }
    return 0;
}
