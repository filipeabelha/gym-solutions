#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

const int N = 1e3+10;
int tc, c, r, lab[N][N], vis[N][N], viss[N][N], dis[N][N];
int mmaxi, maxi, xmaxi, ymaxi;
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
char chr;
queue <pair <int, int> > q;

void bfs(int x, int y) {
    if (dis[x][y] > maxi) maxi = dis[x][y], xmaxi=x, ymaxi=y;
    for (int i = 0; i < 4; i++) {
        int x2 = x+dx[i], y2 = y+dy[i];
        if (x2 < 0 or x2 >= r or y2 < 0 or y2 >= c) continue;
        if (vis[x2][y2]) continue;
        if (lab[x2][y2] == '.') {
            vis[x2][y2] = 1;
            viss[x2][y2] = 1;
            q.push(mp(x2, y2));
            dis[x2][y2] = dis[x][y] + 1;
        }
    }
    while (!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        bfs(qx, qy);
    }
}
int main () {
    scanf("%d", &tc);
    while (tc--) {
        memset(lab, 0, sizeof(lab));
        memset(viss, 0, sizeof(viss));
        mmaxi = 0;
        scanf("%d%d%c", &c, &r, &chr);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                scanf("%c", &chr), lab[i][j] = chr;
            scanf("%c", &chr);
        }

        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        maxi = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (lab[i][j] == '.' and !viss[i][j]) {
                    xmaxi = i;
                    ymaxi = j;
                    vis[i][j] = 1;
                    bfs(i, j);
                    memset(vis, 0, sizeof(vis));
                    memset(dis, 0, sizeof(dis));
                    maxi = 0;
                    vis[xmaxi][ymaxi] = 1;
                    bfs(xmaxi, ymaxi);
                    if (maxi > mmaxi) mmaxi = maxi;
                }
            }
        }
        printf("Maximum rope length is %d.\n", mmaxi);
    }
    return 0;
}
