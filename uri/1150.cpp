#include <bits/stdc++.h>

int main () {
        int x, n;
        scanf("%d", &x);
        while (1) {
                scanf("%d", &n);
                if (n > x) break;
        };
        int sum = x;
        int terms = 1;
        while (sum < n) sum += x+terms, terms++;
        printf("%d\n", terms);
        return 0;
}
