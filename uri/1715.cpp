#include <bits/stdc++.h>

int main () {
    int n, m;
    int sum = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int gols = 0;
        for (int j = 0; j < m; j++) {
            int gol;
            scanf("%d", &gol);
            if (gol > 0) gols++;
        };
        if (gols >= m) sum++;
    };
    printf("%d\n", sum);
    return 0;
}
