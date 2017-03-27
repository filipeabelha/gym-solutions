#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5+10;

int tc, ppl, ans, it, m, n, vis[N];

vector <vector <int> > adjlist(N);

void dfs(int x) {
    vis[x] = 1;
    for (int i = 0; i < adjlist[x].size(); i++)
        if (!vis[adjlist[x][i]])
            dfs(adjlist[x][i]);
}

int main () {
    scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < N; i++) adjlist[i].clear();
        memset(vis, 0, sizeof(vis));
        ans = 0;
        scanf("%d%d", &ppl, &it);
        for (int i = 0; i < it; i++) {
            scanf("%d%d", &m, &n);
            adjlist[m].pb(n);
            adjlist[n].pb(m);
        }
        for (int i = 0; i < ppl; i++) if (!vis[i]) ans++, dfs(i);
        printf("%d\n", ans);
    }
    return 0;
}
