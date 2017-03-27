#include <bits/stdc++.h>

int main () {
    int a, b, c;
    while (1) {
        scanf("%d", &a);
        if (a == 0) break;
        scanf("%d%d", &b, &c);
        int lado = pow(a * b * (100/(double) c), 0.5);
        printf("%d\n", lado);
    }
    return 0;
}
