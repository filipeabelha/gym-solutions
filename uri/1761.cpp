#include <bits/stdc++.h>

const double PI = acos(-1);

double a, b, c;

int main () {
    while (scanf("%lf%lf%lf", &a, &b, &c) != EOF) {
        printf("%.2lf\n", 5*(b*tan(a*PI/180)+c));
    }
    return 0;
}
