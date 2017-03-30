#include <bits/stdc++.h>
using namespace std;

int n;
long double ans;

int main () {
    while (~scanf("%d", &n)) {
        ans = 2*n*n*pow(3, 0.5)/5;
        printf("%.2Lf\n", ans);
    }
    return 0;
}
