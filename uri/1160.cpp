#include <bits/stdc++.h>

int main () {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int pa, pb;
            double ga, gb;
            scanf("%d %d %lf %lf", &pa, &pb, &ga, &gb);
            int anos = 0;
            while (pa <= pb) {
                    pa *= (1 + ga/100.000000);
                    pb *= (1 + gb/100.000000);
                    anos++;
                    if (anos > 100) break;
            };
            if (anos > 100) printf("Mais de 1 seculo.\n"); else printf("%d anos.\n", anos);
        };
        return 0;
}
