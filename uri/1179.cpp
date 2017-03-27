#include <bits/stdc++.h>

int main () {
        int impar[5];
        int par[5];

        int qimp = 0;
        int qpar = 0;

        for (int i = 0; i < 15; i++) {
                if (qimp == 5) {
                        printf("impar[0] = %d\n", impar[0]);
                        printf("impar[1] = %d\n", impar[1]);
                        printf("impar[2] = %d\n", impar[2]);
                        printf("impar[3] = %d\n", impar[3]);
                        printf("impar[4] = %d\n", impar[4]);
                        qimp = 0;
                }
                if (qpar == 5) {
                        printf("par[0] = %d\n", par[0]);
                        printf("par[1] = %d\n", par[1]);
                        printf("par[2] = %d\n", par[2]);
                        printf("par[3] = %d\n", par[3]);
                        printf("par[4] = %d\n", par[4]);
                        qpar = 0;
                }
                int n;
                scanf("%d", &n);
                if (n % 2 != 0) impar[qimp] = n, qimp++; else par[qpar] = n, qpar++;
        };
        for (int i = 0; i < qimp; i++) {
                printf("impar[%d] = %d\n", i, impar[i]);
        };
        for (int i = 0; i < qpar; i++) {
                printf("par[%d] = %d\n", i, par[i]);
        };
        return 0;
}
