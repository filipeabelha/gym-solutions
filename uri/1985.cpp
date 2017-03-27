#include <bits/stdc++.h>

int main () {
        int n;
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
                int p, q;
                scanf("%d %d", &p, &q);
                if (p == 1001) sum += q * 150;
                if (p == 1002) sum += q * 250;
                if (p == 1003) sum += q * 350;
                if (p == 1004) sum += q * 450;
                if (p == 1005) sum += q * 550;
        };
        float res = sum/100.00;
        printf("%.2f\n", res);
        return 0;
}
