#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%c%d", &a, &chr, &b);
        if (a == b) {
            printf("%d\n", a*b);
            continue;
        }
        if (chr > 95) {
            printf("%d\n", a+b);
            continue;
        } else
            printf("%d\n", b-a);
    }
    return 0;
}
