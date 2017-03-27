#include <bits/stdc++.h>

int main () {
        int n, c = 1;
        while(scanf("%d", &n) != EOF) {
                if (n == 0) {
                        printf("Caso %d: 1 numero\n0\n\n", c), c++;
                        continue;
                } else if (n == 1) {
                        printf("Caso %d: 2 numeros\n0 1\n\n", c), c++;
                        continue;
                } else {
                        int sum = 2;
                        for (int i = 2; i <= n; i++) sum += i;
                        printf("Caso %d: %d numeros\n0 1", c, sum);
                        for (int i = 2; i <= n; i++) {
                                for (int j = 1; j <= i; j++) printf(" %d", i);
                        }
                        printf("\n\n"), c++;
                }
        }
        return 0;
}
