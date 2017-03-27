#include <bits/stdc++.h>

int main () {
        while(1) {
                int n;
                scanf("%d", &n);
                if (n == 0) break;
                int maria = 0, joao = 0;
                for (int i = 0; i < n; i++) {
                        int k;
                        scanf("%d", &k);
                        if (k == 0) maria++; else joao++;
                };
                printf("Mary won %d times and John won %d times\n", maria, joao);
        };
        return 0;
}
