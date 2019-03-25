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
const int N = 3e5+5;

vi adj[N], adjt[N];
int ord[N], ordn, scc[N], sccn, sz[N], vis[N], c[N], mini[N], cnt[N];
set <int> adjs[N];
int n, m, a, b;

void dfs (int u) {
    vis[u] = 1;
    for (int v : adj[u]) if (!vis[v]) dfs(v);
    ord[ordn++] = u;
}

void dfst (int u) {
    vis[u] = 0;
    for (int v : adjt[u]) if (vis[v]) dfst(v);
    scc[u] = sccn;
    sz[sccn]++;
    if (mini[sccn] == c[u]) {
        cnt[sccn]++;
    }
    if (mini[sccn] > c[u]) {
        mini[sccn] = c[u];
        cnt[sccn] = 1;
    }
}

int main () {
    cl(mini, 63);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);

    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adjt[b].pb(a);
    }

    sccn = ordn = 1;
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
    for (int i = n; i >= 1; i--) if (vis[ord[i]]) dfst(ord[i]), sccn++; sccn--;

    ll ansa = 0;
    for (int i = 1; i <= sccn; i++) ansa += mini[i];

    ll ansb = 1;
    for (int i = 1; i <= sccn; i++) ansb *= cnt[i], ansb %= MOD;

    printf("%lld %lld\n", ansa, ansb);
    return 0;
}
