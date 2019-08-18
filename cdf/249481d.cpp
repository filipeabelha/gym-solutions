#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m;
int a[N][N], b[N][N];

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }

    for (int i = 1; i < N; i++) b[i][i] = 1;

    printf("%d %d %d %d\n", n, m, m, m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            printf("%d%c", a[i][j], " \n"[j==m]);

    printf("\n");
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            printf("%d%c", b[i][j], " \n"[j==m]);

    return 0;
}

