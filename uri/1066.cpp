#include <bits/stdc++.h>

int main () {
        int pos = 0;
        int neg = 0;
        int par = 0;
        for (int i = 0; i < 5; i++) {
                int n;
                scanf("%d", &n);
                if (n % 2 == 0) par++;
                if (n > 0) pos++;
                if (n < 0) neg++;
        };
        printf("%d valor(es) par(es)\n%d valor(es) impar(es)\n%d valor(es) positivo(s)\n%d valor(es) negativo(s)\n", par, 5-par, pos, neg);
        return 0;
}
