#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2e3+10;

int tc, vis[N], clr[N], b, it, m, n, err;
vector <vector <int> > adj(N);
queue <int> q;

void bfs (int x) {
    vis[x] = 1;
    for (int i = 0; i < adj[x].size(); i++) {
        int el = adj[x][i];
        if (!vis[el]) {
            if (!clr[el])
                clr[el] = -1*(clr[x]);
            else if (clr[el] == clr[x]) {
                err = 1;
                return;
            }
            q.push(el);
        }
    }
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        bfs(a);
    }
}

int main () {
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        scanf("%d%d", &b, &it);

        for (int i = 0; i < N; i++) adj[i].clear();
        memset(vis, 0, sizeof(vis));
        memset(clr, 0, sizeof(clr));
        err = 0;

        for (int i = 1; i <= it; i++) {
            scanf("%d%d", &m, &n);
            adj[m].pb(n);
            adj[n].pb(m);
        }

        for (int i = 1; i <= b; i++)
            if (!vis[i]) clr[i] = 1, bfs(i);

        printf("Scenario #%d:\n", t);

        if (err) printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
    }
    return 0;
}
