#include <bits/stdc++.h>

int rep;
double add;

int main () {
    scanf("%d", &rep);
    while (rep--) {
        add += 2;
        add = 1/add;
    }
    printf("%.10lf\n", add+1);
    return 0;
}
