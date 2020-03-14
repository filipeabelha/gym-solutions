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
const int N = 25e2+5;
const int K = 20;
const int M = K+5;

int n;
vector <pii> adj[N];
int vis[N], h[N], a[N][N], anc[N][M], mx[N][M];
int par[N], sz[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

void dfs (int u) {
    vis[u] = 1;
    for (auto p : adj[u]) {
        int v = p.st;
        int w = p.nd;
        if (!vis[v]) {
            h[v] = h[u]+1;
            anc[v][0] = u;
            mx[v][0] = w;
            dfs(v);
        }
    }
}

void build () {
    anc[1][0] = 1;
    dfs(1);
    for (int j = 1; j <= K; j++) for (int i = 1; i <= n; i++) {
        anc[i][j] = anc[anc[i][j-1]][j-1];
        mx[i][j] = max(mx[i][j-1], mx[anc[i][j-1]][j-1]);
    }
}

int mxedge (int u, int v) {
    int ans = 0;

    if (h[u] < h[v]) swap(u, v);
    for (int j = K; j >= 0; j--) if (h[anc[u][j]] >= h[v]) {
        ans = max(ans, mx[u][j]);
        u = anc[u][j];
    }
    if (u == v) return ans;
    for (int j = K; j >= 0; j--) if (anc[u][j] != anc[v][j]) {
        ans = max(ans, mx[u][j]);
        ans = max(ans, mx[v][j]);
        u = anc[u][j];
        v = anc[v][j];
    }
    return max({ans, mx[u][0], mx[v][0]});
}

vector <piii> edges;

int main () {
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            edges.pb({a[i][j], {i, j}});
        }
    }

    int ok = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i][i] != 0) ok = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != a[j][i]) ok = 0;
        }
    }

    if (ok) {
        sort(edges.begin(), edges.end());
        for (auto e : edges) {
            int w = e.st;
            int u = e.nd.st;
            int v = e.nd.nd;
            if (find(u) != find(v)) {
                unite(u, v);
                adj[v].pb({u, w});
                adj[u].pb({v, w});
            }
        }
        build();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (mxedge(i, j) != a[i][j]) {
                    ok = 0;
                }
            }
        }
    }

    printf("%sMAGIC\n", ok ? "" : "NOT ");

    return 0;
}
