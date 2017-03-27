#include <bits/stdc++.h>

using namespace std;

int n;
double mini, maxi;

int main () {
    scanf("%d", &n);
    mini = n/log(n);
    maxi = 1.25506*mini;
    printf("%.1lf %.1lf\n", mini, maxi);
    return 0;
}
