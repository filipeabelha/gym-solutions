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

int vis[N], ord[N], ordn, scc[N], sccn;
vi adj[N], adjt[N];
int n, m, a, b;
set <int> adjs[N], comps;

void dfs (int u) {
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v]) dfs(v);
    ord[ordn++] = u;
}

void dfst (int u) {
    vis[u] = 0;
    for (auto v : adjt[u]) if (vis[v]) dfst(v);
    scc[u] = sccn;
}

void dfss (int u) {
    vis[u] = 1;
    for (auto v : adjs[u]) if (!vis[v]) dfss(v);
    if (adjs[u].empty()) comps.insert(u);
}

int main () {
    while (~scanf("%d", &n) and n) {
        for (int i = 0; i < N; i++) adj[i].clear(), adjt[i].clear(), adjs[i].clear();
        comps.clear();
        cl(ord, 0);
        cl(scc, 0);
        cl(vis, 0);
        ordn = sccn = 1;

        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adjt[b].pb(a);
        }

        for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
        for (int i = n; i >= 1; i--) if (vis[ord[i]]) dfst(ord[i]), sccn++; sccn--;
        for (int i = 1; i <= n; i++) for (auto v : adj[i]) if (scc[i] != scc[v]) adjs[scc[i]].insert(scc[v]);

        for (int i = 1; i <= sccn; i++) dfss(i);
        for (int i = 1; i <= n; i++) if (comps.count(scc[i])) printf("%d ", i);
        printf("\n");
    }
    return 0;
}
