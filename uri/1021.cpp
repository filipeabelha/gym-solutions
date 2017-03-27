#include <bits/stdc++.h>

int main () {
        double n;
        scanf("%lf", &n);

        int n100 = n / 100;
        n -= 100*n100;
        int n50 = n / 50;
        n -= 50*n50;
        int n20 = n / 20;
        n -= 20*n20;
        int n10 = n / 10;
        n -= 10*n10;
        int n5 = n / 5;
        n -= 5*n5;
        int n2 = n / 2;
        n -= 2*n2;
        int m1 = n / 1;
        n -= 1*m1;
        int m50 = n / 0.50;
        n -= 0.50*m50;
        int m25 = n / 0.25;
        n -= 0.25*m25;
        int m10 = n / 0.10;
        n -= 0.10*m10;
        int m05 = n / 0.05;
        n -= 0.05*m05;
        float k = 100*n;
        int m01 = k;

        printf("NOTAS:\n%d nota(s) de R$ 100.00\n%d nota(s) de R$ 50.00\n%d nota(s) de R$ 20.00\n%d nota(s) de R$ 10.00\n%d nota(s) de R$ 5.00\n%d nota(s) de R$ 2.00\nMOEDAS:\n%d moeda(s) de R$ 1.00\n%d moeda(s) de R$ 0.50\n%d moeda(s) de R$ 0.25\n%d moeda(s) de R$ 0.10\n%d moeda(s) de R$ 0.05\n%d moeda(s) de R$ 0.01\n", n100, n50, n20, n10, n5, n2, m1, m50, m25, m10, m05, m01);
        return 0;
}
