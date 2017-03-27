#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5+10;
int tc, m, n, vis[N], dis[N], xmaxdis, maxdis;
vector <vector <int> > adjlist(N);
queue <int> q;

void bfs (int x) {
    vis[x] = 1;
    if (dis[x] > maxdis) maxdis = dis[x], xmaxdis = x;
    for (int i = 0; i < adjlist[x].size(); i++)
        if (!vis[adjlist[x][i]])
            q.push(adjlist[x][i]), dis[adjlist[x][i]] = dis[x]+1;
    while (!q.empty()) {
        int z = q.front(); q.pop();
        bfs(z);
    }
}

int main () {
    scanf("%d", &tc);
    while (tc--) {
        int it;
        scanf("%d", &it);
        for (int i = 0; i < N; i++) adjlist[i].clear();
        for (int i = 1; i <= it-1; i++) {
            scanf("%d%d", &m, &n);
            adjlist[m].pb(n);
            adjlist[n].pb(m);
        }
        maxdis = 0;
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        bfs(0);
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        bfs(xmaxdis);
        printf("%d\n", maxdis/2 + (maxdis%2==1));
    }
    return 0;
}
