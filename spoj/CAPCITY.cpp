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
vi ans;

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
    vis[u]++;
    for (auto v : adjs[u]) dfss(v);
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adjt[b].pb(a);
    }
    ordn = sccn = 1;
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
    for (int i = n; i >= 1; i--) if (vis[ord[i]]) dfst(ord[i]), sccn++; sccn--;
    for (int i = 1; i <= n; i++) for (auto v : adj[i]) if (scc[i] != scc[v]) adjs[scc[i]].insert(scc[v]);
    for (int i = 1; i <= sccn; i++) dfss(i);
    for (int i = 1; i <= sccn; i++) if (vis[i] == sccn) comps.insert(i);
    for (int i = 1; i <= n; i++) if (comps.count(scc[i])) ans.pb(i);
    printf("%d\n", (int) ans.size());
    for (auto x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}
