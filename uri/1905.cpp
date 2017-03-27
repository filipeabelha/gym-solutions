#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define cl(x,v) memset((x), (v), sizeof(x))

typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;

int tc, vis[10][10], m[10][10];
int dx[] = {0, 0, -1, +1};
int dy[] = {-1, +1, 0, 0};

void dfs(int x, int y) {
    if (vis[x][y]) return;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int x2 = x+dx[i], y2 = y+dy[i];
        if (x2 < 0 or x2 >= 5 or y2 < 0 or y2 >= 5) continue;
        if (!vis[x2][y2] and m[x2][y2] == 0)
            dfs(x2, y2);
    }
}

int main () {
    scanf("%d", &tc);
    while (tc--) {
        cl(vis, 0);
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                scanf("%d", &m[i][j]);
        dfs(0,0);
        if (vis[4][4]) printf("COPS\n");
        else printf("ROBBERS\n");
    }
    return 0;
}
