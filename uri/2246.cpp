#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, N = 2e2+10;

int m, n, t[N][N], vis[N][N], res = INF;
int dx[] = {0, 0, -1, +1}, dy[] = {+1, -1, 0, 0};

int dfs (int x, int y) {
    int ans = 1;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (!vis[x+dx[i]][y+dy[i]] and t[x+dx[i]][y+dy[i]] == t[x][y])
            ans += dfs(x+dx[i], y+dy[i]);
    }
    return ans;
}

int main () {
    scanf("%d%d", &m, &n);
    memset(t, -1, sizeof(t));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &t[i][j]);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (!vis[i][j]) {
                int x = dfs(i, j);
                if (x < res) res = x;
            }
    printf("%d\n", res);
}
