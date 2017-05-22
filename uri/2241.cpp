#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, p, x, y, a, b, t1[N][N], t2[N][N];

int main () {

    scanf("%d%d", &n, &p);

    for (int i = 0; i < p; i++) scanf("%d%d", &x, &y), t1[x][y] = 1;
    for (int i = 0; i < p; i++) scanf("%d%d", &x, &y), t2[x][y] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= n; j++)
            t1[i][j] += t1[i][j-1],
            t2[i][j] += t2[i][j-1];

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= n; j++)
            t1[i][j] += t1[i-1][j],
            t2[i][j] += t2[i-1][j];

    for (int l = 1; l <= n; l++)
        for (int i = 1; i+l-1 <= n; i++)
            for (int j = 1; j+l-1 <= n; j++) {
                int ii = i+l-1;
                int jj = j+l-1;
                int k1 = t1[ii][jj] + t1[ii-l][jj-l] - t1[ii-l][jj] - t1[ii][jj-l];
                int k2 = t2[ii][jj] + t2[ii-l][jj-l] - t2[ii-l][jj] - t2[ii][jj-l];
                if (k1 and !k2) a++;
                if (!k1 and k2) b++;
            }

    printf("%d %d\n", a, b);

    return 0;
}
