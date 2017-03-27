#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int tc, ans, vis[10][10], dis[10][10];
int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2};
int dy[] = {+1, -1, +2, -2, +2, -2, +1, -1};
queue <pair <int, int> > q;
char st[5], en[5];

void bfs (int x, int y) {
    if (x > 8 or x < 1 or y > 8 or y < 1) return;
    if (x == en[0] and y == en[1]) ans = dis[x][y];
    for (int i = 0; i < 8; i++)
        if (!vis[x+dx[i]][y+dy[i]]) {
            if (x+dx[i]<=8 and x+dx[i]>=1 and y+dy[i]<=8 and y+dy[i]>=1) {
                q.push(mp(x+dx[i], y+dy[i]));
                vis[x+dx[i]][y+dy[i]] = 1;
                dis[x+dx[i]][y+dy[i]] = dis[x][y]+1;
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
    for (int i = 0; i < 2; i++)
        printf("%d ", matriz[i]);
    scanf("%d", &tc);
    while (tc--) {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        scanf(" %s %s", st, en);
        st[0]-=96;
        st[1]-=48;
        en[0]-=96;
        en[1]-=48;
        vis[st[0]][st[1]] = 1;
        bfs(st[0], st[1]);
        printf("%d\n", ans);
    }
    return 0;
}
