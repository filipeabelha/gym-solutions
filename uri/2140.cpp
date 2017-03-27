#include <bits/stdc++.h>

int notas[] = {2, 5, 10, 20, 50, 100};
int n, m, brk;

int main () {
    while (1) {
        brk = 0;
        scanf("%d%d", &n, &m);
        if (!n and !m) break;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (notas[i]+notas[j] == m-n) {
                    printf("possible\n");
                    brk = 1;
                }
                if (brk) break;
            }
            if (brk) break;
        }
        if (brk) continue;
        printf("impossible\n");
    }
    return 0;
}
