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
const int N = 1e3+5;  // Max number of vertices
const int K = 10;     // Each 1e3 requires ~ 10 K
const int M = K+5;

int n;                // Number of vertices
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
    for (int j = K; j >= 0; j--) if (h[anc[u][j]] >= h[v]) {
        u = anc[u][j];
    }
    if (u == v) return u;
    for (int j = K; j >= 0; j--) if (anc[u][j] != anc[v][j]) {
        u = anc[u][j];
        v = anc[v][j];
    }
    return anc[u][0];
}


int main () {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        printf("Case %d:\n", tc);
        cl(vis, 0);
        cl(h, 0);
        cl(anc, 0);
        for (int i = 0; i < N; i++) adj[i].clear();

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int k;
            scanf("%d", &k);
            while (k--) {
                int j;
                scanf("%d", &j);
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }

        build();

        int q;
        scanf("%d", &q);
        while (q--) {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%d\n", lca(a, b));
        }
    }

    return 0;
}
