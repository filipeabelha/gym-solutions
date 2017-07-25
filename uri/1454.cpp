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
const int N = 1e6+5;

int n, m, q, cnt;
int a, b, d;
int anc[N][30], maxi[N][30];
int vis[N], par[N], h[N];
vector <pii> adj[N];
vector <piii> edges;

int find (int k) { return (par[k] == k ? k : par[k] = find(par[k])); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    par[b] = a;
}

int lca (int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int j = 20; j >= 0; j--) if (h[anc[u][j]] >= h[v]) u = anc[u][j];
    if (u == v) return u;
    for (int j = 20; j >= 0; j--) if (anc[u][j] != anc[v][j]) u = anc[u][j], v = anc[v][j];
    return anc[u][0];
}

void dfs (int u) {
    vis[u] = 1;
    for (auto p : adj[u]) if (!vis[p.st]) {
        int v = p.st;
        int d = p.nd;
        anc[v][0] = u;
        maxi[v][0] = d;
        h[v] = h[u]+1;
        dfs(v);
    }
}

int main () {
    while (~scanf("%d%d", &n, &m) and n and m and ++cnt) {
        edges.clear();
        for (int i = 0; i < N; i++) adj[i].clear();
        for (int i = 0; i < N; i++) par[i] = i;
        cl(anc, 0);
        cl(maxi, -63);
        cl(vis, 0);

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &d);
            edges.pb(mp(d, mp(a, b)));
        }

        sort(edges.begin(), edges.end());
        for (auto e : edges)
            if (find(e.nd.st) != find(e.nd.nd)) {
                unite(e.nd.st, e.nd.nd);
                adj[e.nd.st].pb(mp(e.nd.nd, e.st));
                adj[e.nd.nd].pb(mp(e.nd.st, e.st));
            }

        for (int i = 1; i <= n; i++) if (!vis[i]) anc[i][0] = i, dfs(i);
        for (int j = 1; j <= 20; j++) for (int i = 1; i <= n; i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];
        for (int j = 1; j <= 20; j++) for (int i = 1; i <= n; i++)
            maxi[i][j] = max(maxi[i][j-1], maxi[anc[i][j-1]][j-1]);

        scanf("%d", &q);
        printf("Instancia %d\n", cnt);
        while (q--) {
            scanf("%d%d", &a, &b);
            int l = lca(a, b);
            int ans = -INF;
            for (int j = 20; j >= 0; j--) {
                if (h[anc[a][j]] >= h[l]) {
                    ans = max(ans, maxi[a][j]);
                    a = anc[a][j];
                }
                if (h[anc[b][j]] >= h[l]) {
                    ans = max(ans, maxi[b][j]);
                    b = anc[b][j];
                }
            }
            printf("%d\n", ans < -123456789 ? 0 : ans);
        }
        printf("\n");
    }
    return 0;
}
