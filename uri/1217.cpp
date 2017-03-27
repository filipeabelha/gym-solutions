#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    double pago = 0, kg = 0;
    char chr;
    for (int i = 0; i < n; i++) {
        int kgday = 1;
        double x;
        scanf("%lf", &x);
        pago += x;
        scanf("%c", &chr);
        while (1) {
            scanf("%c", &chr);
            if (chr == 32) kgday++;
            if (chr == 10) break;
        }
        printf("day %d: %d kg\n", i+1, kgday);
        kg += kgday;
    }
    printf("%.2lf kg by day\n", kg / n);
    printf("R$ %.2lf by day\n", pago / n);
    return 0;
}
