#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define cl(x, v) memset((x), (v), sizeof(x))

typedef vector <int> vi;
typedef vector <vi> vii;

const int N = 1e5+10; // Maximum number of nodes
int vis[N], dis[N], nodes, maxdis, xdis, ans;
vector <vector <int> > adj(N);
queue <int> q;

void bfs (int x) {
    if (dis[x] > maxdis) maxdis = dis[x], xdis = x;
    for (int i = 0; i < adj[x].size(); i++) {
        int el = adj[x][i];
        if (!vis[el])
            vis[el] = 1, q.push(el), dis[el] = dis[x]+1;
    }
    while (!q.empty()) {
        int nxt = q.front(); q.pop();
        bfs(nxt);
    }
}

int main () {
    scanf("%d", &nodes);
    for (int i = 0; i < nodes-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    // You can remove this loop if it's a connected graph.
    for (int i = 1; i <= nodes; i++)
        if (!vis[i]) {
            xdis = i;
            maxdis = 0;
            vis[i] = 1;

            bfs(i);

            cl(vis, 0); cl (dis, 0);
            ans = maxdis;
            maxdis = 0;
            vis[xdis] = 1;

            bfs(xdis);

            if (maxdis > ans) ans = maxdis;
        }
    
    printf("%d\n", ans);
    
    return 0;
}

