#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m, t[N][N], ans[N][N];
int dx[] = {-1, +0, +0, +1};
int dy[] = {+0, +1, -1, +0};

int main () {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
            scanf("%d", &t[i][j]), ans[i][j] = 0;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
            if (t[i][j]) for (int k = 0; k < 4; k++) ans[i+dx[k]][j+dy[k]]++;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                printf("%d", t[i][j] == 1 ? 9 : ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}
