#include <bits/stdc++.h>

double res = 3, add;
int rep;

int main () {
    scanf("%d", &rep);
    for (int i = 0; i < rep; i++) {
        add += 6;
        add = 1/add;
    }
    printf("%.10f\n", res+add);
    return 0;
}
