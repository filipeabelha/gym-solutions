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
    for (int j = 20; j >= 0; j--) if (h[anc[u][j]] >= h[v]) u = anc[u][j];
    if (u == v) return u;
    for (int j = 20; j >= 0; j--) if (anc[u][j] != anc[v][j]) u = anc[u][j], v = anc[v][j];
    return anc[u][0];
}

int dist (int u, int v) {
    return h[u]+h[v]-2*h[lca(u,v)];
}

int q, a, b, c, d;

int main () {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n-1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    build();
    while (q--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int x = dist(a,b)+dist(c,d);
        int y = min(dist(a,c)+dist(b,d), dist(a,d)+dist(b,c));
        if (y > x) printf("0\n");
        else       printf("%d\n", (x-y)/2+1);
    }
    return 0;
}
