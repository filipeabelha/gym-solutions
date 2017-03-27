#include <bits/stdc++.h>

const double PI = acos(-1);

int main () {
    double n;
    while (scanf("%lf", &n) != EOF)
        printf("%.10lf\n", n * (sin(108*PI/180) / sin(63*PI/180)));
    return 0;
}
