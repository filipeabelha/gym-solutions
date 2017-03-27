#include <bits/stdc++.h>

int n;
double ans;

int main () {
    scanf("%d", &n);
    ans = (pow((1+pow(5,0.5))/2, n) - pow((1-pow(5,0.5))/2, n))/(pow(5,0.5));
    printf("%.1f\n", ans);
    return 0;
}
