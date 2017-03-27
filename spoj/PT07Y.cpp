#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e4+10;

int n, e, p, q, err, vis[N];
vector <vector <int> > adj(N);

void dfs(int x) {
    vis[x] = 1;
    for (int i = 0; i < adj[x].size(); i++) {
        if (!vis[adj[x][i]])
            dfs(adj[x][i]);
    }
}

int main () {
    scanf("%d%d", &n, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &p, &q);
        adj[p].pb(q);
        adj[q].pb(p);
    }
    if (n-e != 1) err = 1; else dfs(1);
    for (int i = 1; i <= n; i++) if (!vis[i]) err = 1;
    if (err) printf("NO\n"); else printf("YES\n");
    return 0;
}
