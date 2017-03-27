#include <bits/stdc++.h>

int min (int x, int y) {
    return x < y ? x : y;
}

int max (int x, int y) {
    return x > y ? x : y;
}

int main () {
    int x, y;
    while (1) {
        scanf("%d%d", &x, &y);
        if (x == 0 and y == 0) break;
        printf("%d\n", 2*min(x,y)-max(x,y));
    }
    return 0;
}
