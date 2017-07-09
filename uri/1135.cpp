#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, x, u, v, q;
int anc[N][30], vis[N], h[N];
ll w, dist[N];
vector <pair <int, ll> > adj[N];

void dfs (int u) {
    vis[u] = 1;
    for (auto p : adj[u]) {
        int v = p.st;
        if (!vis[v]) {
            h[v] = h[u]+1;
            dist[v] = dist[u]+p.nd;
            anc[v][0] = u;
            dfs(v);
        }
    }
}

int lca (int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int j = 20; j >= 0; j--) if (h[anc[u][j]] >= h[v]) u = anc[u][j];
    if (u == v) return u;
    for (int j = 20; j >= 0; j--) if (anc[u][j] != anc[v][j]) u = anc[u][j], v = anc[v][j];
    return anc[u][0];
}

int main () {
    while (~scanf("%d", &n) and n) {
        for (int i = 2; i <= n; i++) {
            scanf("%d%lld", &x, &w);
            adj[x+1].pb(mp(i, w));
            adj[i].pb(mp(x+1, w));
        }
        anc[1][0] = 1;
        dfs(1);
        for (int j = 1; j <= 20; j++) for (int i = 1; i <= n; i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf("%d%d", &u, &v); u++; v++;
            printf("%lld%s", dist[u]+dist[v]-2*dist[lca(u,v)], i < q-1 ? " " : "\n");
        }
        cl(anc, 0);
        cl(h, 0);
        cl(vis, 0);
        cl(dist, 0);
        for (int i = 0; i < N; i++) adj[i].clear();
    }
    return 0;
}

