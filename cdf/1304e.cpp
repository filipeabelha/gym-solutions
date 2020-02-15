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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

const int K = 20;
const int M = K+5;

int n;
vi adj[N];
int vis[N], h[N], anc[N][M];

void dfs (int u) {
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v]) {
        h[v] = h[u]+1;
        anc[v][0] = u;
        dfs(v);
    }
}

void build () {
    anc[1][0] = 1;
    dfs(1);
    for (int j = 1; j <= K; j++) for (int i = 1; i <= n; i++)
        anc[i][j] = anc[anc[i][j-1]][j-1];
}

int lca (int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int j = 20; j >= 0; j--) if (h[anc[u][j]] >= h[v]) {
        u = anc[u][j];
    }
    if (u == v) return u;
    for (int j = 20; j >= 0; j--) if (anc[u][j] != anc[v][j]) {
        u = anc[u][j];
        v = anc[v][j];
    }
    return anc[u][0];
}

int dist (int u, int v) {
    return h[u] + h[v] - 2*h[lca(u, v)];
}


int main () {
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    build();
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y, a, b, k;
        scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);

        int ok = 0;

        int d1 = dist(a, b);
        int d2 = dist(a, x) + dist(y, b) + 1;
        int d3 = dist(a, y) + dist(x, b) + 1;
        int d4 = dist(a, x) + dist(x, b);
        int d5 = dist(a, y) + dist(y, b);

        if (k >= d1 and (k-d1)%2 == 0) ok = 1;
        if (k >= d2 and (k-d2)%2 == 0) ok = 1;
        if (k >= d3 and (k-d3)%2 == 0) ok = 1;
        if (k >= d4 and (k-d4)%2 == 0) ok = 1;
        if (k >= d5 and (k-d5)%2 == 0) ok = 1;

        printf("%s\n", ok ? "YES" : "NO");
    }

    return 0;
}
