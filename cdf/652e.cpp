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
const int N = 3e5+5;

set <pii> adjd[N], adj[N], adjt[N], adjs[N];
int ok[N], ord[N], ordn, scc[N], sccn, sz[N], vis[N], yes;
int n, m, a, b, k, visCnt;

void direct (int u, int par) {
    vis[u] = ++visCnt;
    for (auto p : adjd[u]) {
        int v = p.st;
        int w = p.nd;
        if (v != par and !adjt[u].count({v, w})) {
            adj[u].insert({v, w});
            adjt[v].insert({u, w});
            if (!vis[v]) direct(v, u);
        }
    }
}

void dfs (int u) {
    vis[u] = 1;
    for (auto p : adj[u]) {
        int v = p.st;
        int w = p.nd;
        if (!vis[v]) dfs(v);
    }
    ord[ordn++] = u;
}

void dfst (int u) {
    vis[u] = 0;
    scc[u] = sccn;
    sz[sccn]++;
    for (auto p : adjt[u]) {
        int v = p.st;
        int w = p.nd;
        if (vis[v]) dfst(v);
    }
}

void dfss (int u, int ans, int dest) {
    ans |= ok[u];
    vis[u] = 1;

    if (u == dest and ans) yes = 1;
    for (auto p : adjs[u]) {
        int v = p.st;
        int w = p.nd;
        if (!vis[v]) dfss(v, ans|w, dest);
    }
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a, &b, &k);
        adjd[a].insert({b, k});
        adjd[b].insert({a, k});
    }

    direct(1, 1);

    cl(vis, 0);
    sccn = ordn = 1;
    dfs(1);
    for (int i = ordn; i >= 1; i--) if (vis[ord[i]]) dfst(ord[i]), sccn++; sccn--;

    for (int i = 1; i <= n; i++) {
        for (auto p : adj[i]) {
            int v = p.st;
            int w = p.nd;
            if (scc[i] != scc[v]) {
                adjs[scc[i]].insert({scc[v], w});
                adjs[scc[v]].insert({scc[i], w});
            } else {
                ok[scc[i]] |= w;
            }
        }
    }

    scanf("%d%d", &a, &b);
    dfss(scc[a], ok[scc[a]], scc[b]);

    printf("%s\n", yes ? "YES" : "NO");

    return 0;
}
