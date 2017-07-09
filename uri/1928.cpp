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
const int N = 5e4+5;

int n;
int h[N], anc[N][30], vis[N];
vi pos[N], adj[N];

void dfs (int u) {
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v]) {
        h[v] = h[u]+1;
        anc[v][0] = u;
        dfs(v);
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
    scanf("%d", &n);
    for (int x, i = 1; i <= n; i++) scanf("%d", &x), pos[x].pb(i);
    for (int a, b, i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1);

    anc[1][0] = 1;
    for (int j = 1; j <= 20; j++)
        for (int i = 1; i <= n; i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];

    ll ans = 0;
    for (int i = 1; i <= n/2; i++) {
        int a = pos[i][0];
        int b = pos[i][1];
        ans += h[a] + h[b] - 2*h[lca(a,b)];
    }

    printf("%lld\n", ans);

    return 0;
}
