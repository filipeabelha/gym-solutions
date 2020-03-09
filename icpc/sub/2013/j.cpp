#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;
const int K = 20;
const int M = K+5;

int par[N], sz[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

int n, m, q;
vector <piii> edges;
vector <pii> adj[N];
int vis[N], h[N], anc[N][M], mn[N][M];

void dfs (int u) {
    vis[u] = 1;
    for (auto p : adj[u]) {
        int v = p.st;
        int w = p.nd;
        if (!vis[v]) {
            h[v] = h[u]+1;
            anc[v][0] = u;
            mn[v][0] = w;
            dfs(v);
        }
    }
}

void build () {
    anc[1][0] = 1;
    cl(mn, 63);
    dfs(1);
    for (int j = 1; j <= K; j++) for (int i = 1; i <= n; i++) {
        anc[i][j] = anc[anc[i][j-1]][j-1];
        mn[i][j] = min(mn[i][j-1], mn[anc[i][j-1]][j-1]);
    }
}

int mnedge (int u, int v) {
    int ans = INF;

    if (h[u] < h[v]) swap(u, v);
    for (int j = K; j >= 0; j--) if (h[anc[u][j]] >= h[v]) {
        ans = min(ans, mn[u][j]);
        u = anc[u][j];
    }
    if (u == v) return ans;
    for (int j = K; j >= 0; j--) if (anc[u][j] != anc[v][j]) {
        ans = min(ans, mn[u][j]);
        ans = min(ans, mn[v][j]);
        u = anc[u][j];
        v = anc[v][j];
    }
    return min({ans, mn[u][0], mn[v][0]});
}

int main () {
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;

    scanf("%d%d%d", &n, &m, &q);
    while (m--) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges.pb({-w, {a, b}});
    }

    sort(edges.begin(), edges.end());

    for (auto e : edges) {
        int w = -e.st;
        int a = e.nd.st;
        int b = e.nd.nd;
        if (find(a) == find(b)) continue;
        unite(a, b);
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    build();

    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", mnedge(a, b));
    }


    return 0;
}
