#include <bits/stdc++.h>

int main () {
        int n, min, imin = 0, v[2000];
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        min = v[0];
        for (int i = 0; i < n; i++) if (min > v[i]) min = v[i], imin = i;
        printf("Menor valor: %d\nPosicao: %d\n", min, imin);
        return 0;
}
