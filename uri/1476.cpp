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
const int N = 2e4+5;

int n, m, s, a, b, w;
int par[N], h[N], vis[N], anc[N][30], mini[N][30];
vector <piii> edges;
vector <pii> adj[N];

int find (int k) {
    return (par[k] == k ? k : par[k] = find(par[k]));
}

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    par[b] = a;
}

void dfs (int u) {
    vis[u] = 1;
    for (auto p : adj[u]) {
        int v = p.st;
        int w = p.nd;
        if (!vis[v]) {
            h[v] = h[u] + 1;
            anc[v][0] = u;
            mini[v][0] = w;
            dfs(v);
        }
    }
}

int lca (int u, int v) {
    if (h[v] > h[u]) swap(u, v);
    for (int j = 20; j >= 0; j--) if (h[anc[u][j]] >= h[v]) u = anc[u][j];
    if (u == v) return u;
    for (int j = 20; j >= 0; j--) if (anc[u][j] != anc[v][j]) u = anc[u][j], v = anc[v][j];
    return anc[u][0];
}

int main () {
    while (~scanf("%d%d%d", &n, &m, &s)) {
        edges.clear();
        for (int i = 0; i < N; i++) par[i] = i;
        for (int i = 0; i < N; i++) adj[i].clear();
        cl(h, 0);
        cl(anc, 0);
        cl(mini, 63);
        cl(vis, 0);

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &w);
            edges.pb(mp(-w, mp(a, b)));
        }
        sort(edges.begin(), edges.end());
        for (auto p : edges) {
            if (find(p.nd.st) != find(p.nd.nd)) {
                unite(p.nd.st, p.nd.nd);
                adj[p.nd.st].pb(mp(p.nd.nd, -p.st));
                adj[p.nd.nd].pb(mp(p.nd.st, -p.st));
            }
        }

        anc[1][0] = 1;
        dfs(1);
        for (int j = 1; j <= 20; j++)
            for (int i = 1; i <= n; i++) {
                anc[i][j] = anc[anc[i][j-1]][j-1];
                mini[i][j] = min(mini[i][j-1], mini[anc[i][j-1]][j-1]);
            }

        for (int i = 0; i < s; i++) {
            scanf("%d%d", &a, &b);
            int l = lca(a, b);
            int ans = INF;
            if (a != l) {
                for (int j = 20; j >= 0; j--) {
                    if (h[anc[a][j]] > h[l]) {
                        ans = min(ans, mini[a][j]);
                        a = anc[a][j];
                    }
                }
                ans = min(ans, mini[a][0]);
            }
            if (b != l) {
                for (int j = 20; j >= 0; j--) {
                    if (h[anc[b][j]] > h[l]) {
                        ans = min(ans, mini[b][j]);
                        b = anc[b][j];
                    }
                }
                ans = min(ans, mini[b][0]);
            }
            printf("%d\n", (ans == INF ? -1 : ans));
        }
    }
    return 0;
}
