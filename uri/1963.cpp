#include <bits/stdc++.h>

int main () {
        double a, b;
        scanf("%lf %lf", &a, &b);
        double aumento = (b/a-1) * 100;
        printf("%.2lf%%\n", aumento);
        return 0;
}
