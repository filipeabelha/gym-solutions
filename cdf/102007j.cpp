#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;

double area (double a, double b, double c) {
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int a, b, c, d;
double ans;

int main () {
    scanf("%d%d%d%d", &a, &b, &c, &d);

    for (double ct = -1-EPS; ct <= 1+EPS; ct += EPS) {
        double x = a*a + b*b -2*a*b*ct;
        if (x-EPS < 0) break;
        x = sqrt(x);

        if (x-EPS > a+b) continue;
        if (x-EPS > c+d) continue;

        if (a-EPS > x+b) continue;
        if (b-EPS > a+x) continue;
        if (c-EPS > x+d) continue;
        if (d-EPS > c+x) continue;

        ans = max(ans, area(x, a, b) + area(x, c, d));
    }

    for (double ct = -1-EPS; ct <= 1+EPS; ct += EPS) {
        double x = a*a + d*d -2*a*d*ct;
        if (x-EPS < 0) break;
        x = sqrt(x);

        if (x-EPS > a+d) continue;
        if (x-EPS > c+b) continue;

        if (a-EPS > x+d) continue;
        if (d-EPS > a+x) continue;
        if (c-EPS > x+b) continue;
        if (b-EPS > c+x) continue;

        ans = max(ans, area(x, a, d) + area(x, c, b));
    }
    printf("%.6lf\n", ans);

}
