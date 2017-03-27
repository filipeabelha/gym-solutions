#include <bits/stdc++.h>

int main () {
        while (1) {
                int n;
                scanf("%d", &n);
                if (n == 0) break;
                if (n % 2 != 0) n++;
                int sum = 5*n + 20;
                printf("%d\n", sum);
        };
        return 0;
}
