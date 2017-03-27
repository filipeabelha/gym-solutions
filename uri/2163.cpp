#include <bits/stdc++.h>

int n, m, mtx[1005][1005], ok;

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        scanf("%d", &mtx[i][j]);
    for (int i = 2; i <= n-1; i++) for (int j = 2; j <= m-1; j++)
        if (mtx[i][j]==42 and mtx[i-1][j]==7 and mtx[i+1][j]==7 and mtx[i-1][j-1]==7 and mtx[i][j-1]==7 and mtx[i+1][j-1]==7 and mtx[i-1][j+1]==7 and mtx[i][j+1]==7 and mtx[i+1][j+1]==7)
            printf("%d %d\n", i, j), ok = 1;
    if (!ok) printf("0 0\n");
    return 0;
}
