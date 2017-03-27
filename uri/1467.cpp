#include <bits/stdc++.h>

int main () {
        int a, b, c;
        while (scanf("%d %d %d", &a, &b, &c) != EOF) {
                if ((a == 0 or a == 1) and (b == 0 or b == 1) and (c == 0 or c == 1)) {
                        if (a == b and b == c) {printf("*\n"); continue;};
                        if (b == c and c != a) {printf("A\n"); continue;};
                        if (a == c and c != b) {printf("B\n"); continue;};
                        if (a == b and b != c) {printf("C\n"); continue;};
                };
        };
        return 0;
}
