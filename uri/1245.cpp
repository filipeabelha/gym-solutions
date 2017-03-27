#include <bits/stdc++.h>

int mini (int a, int b) {
    return (a <= b) ? a : b;
}

int main () {
    int n;
    while(scanf("%d", &n) != EOF) {
        int res = 0;
        int estoque[70][2];
        memset(estoque, 0, sizeof(estoque));
        for (int i = 0; i < n; i++) {
            int num;
            char pe;
            scanf(" %d %c", &num, &pe);
            if (pe == 'E') estoque[num][0]++;
            if (pe == 'D') estoque[num][1]++;
        }
        for (int i = 0; i < 65; i++) {
            res += mini(estoque[i][0], estoque[i][1]);
        }
        printf("%d\n", res);
    }
    return 0;
}
