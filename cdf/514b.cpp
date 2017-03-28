#include <bits/stdc++.h>

int mdc (int a, int b) {
    if    (a == 0 && b == 0)  return 1;
    if    (a == 0)        return b;
    if    (b == 0)        return a;
    if    (a % b == 0)    return b;
    else                  return mdc (b, a % b);
}

int main () {
    int n, x0, y0, stormx[1050], stormy[1050], okx[1050], oky[1050], tiros = 0;
    memset(okx, 0, sizeof(okx));
    memset(oky, 0, sizeof(oky));
    scanf("%d%d%d\n", &n, &x0, &y0);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &stormx[i], &stormy[i]);
        int m = abs(mdc (stormx[i] - x0, stormy[i] - y0));
        stormx[i] = ((stormx[i] - x0) / m) + x0;
        stormy[i] = ((stormy[i] - y0) / m) + y0;
        if (stormx[i] <= x0) {
            stormx[i] = 2*x0 - stormx[i];
            stormy[i] = 2*y0 - stormy[i];
        };
        if ((stormx[i] == x0) && (stormy[i] < y0)) {
            stormx[i] = 2*x0 - stormx[i];
            stormy[i] = 2*y0 - stormy[i];
        };
        int dartiro = 1;
        for (int j = 0; j < tiros; j++) if ((okx[j] == stormx[i]) && (oky[j] == stormy[i])) dartiro = 0;        
        if (dartiro == 1) {
            okx[tiros] = stormx[i];
            oky[tiros] = stormy[i];
            tiros++;
        };              
    };
    printf("%d\n", tiros);
    return 0;
}
