#include <bits/stdc++.h>
int x, k, n, h;
int main () {
    scanf("%d%d", &n, &h);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        if (k > h) x++;
        x++;
    } 
    printf("%d\n", x);
    return 0;
}
