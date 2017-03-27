#include <bits/stdc++.h>

int main () {
    int n, a, b, x, y;
    scanf("%d%d%d%d%d", &n, &a, &b, &x, &y);
    int possivel = true;
    if (n < a or n > b or n < x or n > y) possivel = false;
    if (possivel) printf("possivel\n");
    else printf("impossivel\n");
    return 0;
}

