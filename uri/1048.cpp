#include <bits/stdc++.h>

int main () {
        float n;
        scanf("%f", &n);
        int reaj;
        if (n > 2000.00)      reaj = 4;
        else if (n > 1200.00) reaj = 7;
        else if (n > 800.00)  reaj = 10;
        else if (n > 400.00)  reaj = 12;
        else                  reaj = 15;
        float n2 = n * (1 + reaj/100.0000);
        float delta = n2 - n;
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %d %%\n", n2, delta, reaj);
        return 0;
}
