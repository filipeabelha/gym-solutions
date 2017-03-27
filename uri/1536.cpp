#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        scanf("%d x %d", &a, &b);
        scanf("%d x %d", &c, &d);
        if (a == c and b == d) {
            printf("Penaltis\n");
            continue;
        }
        if (a + d > b + c) {
            printf("Time 1\n");
            continue;
        }
        if (b + c > a + d) {
            printf("Time 2\n");
            continue;
        }
        if (b > d) {
            printf("Time 2\n");
        } else {
            printf("Time 1\n");
        }
    }
    return 0;
}
