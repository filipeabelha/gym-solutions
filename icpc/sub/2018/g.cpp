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
const int INF = 1e9, MOD = 1e9+7;
const int M = 1e3+5;
const int N = 2e3+15;

struct edge {int v, c, f;};

int src, snk = N-1, h[N], ptr[N];
vector<edge> edgs;
vector<int> g[N];

void add_edge (int u, int v, int c) {
    int k = edgs.size();
    edgs.push_back({v, c, 0});
    edgs.push_back({u, 0, 0});
    g[u].push_back(k);
    g[v].push_back(k+1);
}

bool bfs() {
    memset(h, 0, sizeof h);
    queue<int> q;
    h[src] = 1;
    q.push(src);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i : g[u]) {
            int v = edgs[i].v;
            if (!h[v] and edgs[i].f < edgs[i].c)
                q.push(v), h[v] = h[u] + 1;
        }
    }
    return h[snk];
}

int dfs (int u, int flow) {
    if (!flow or u == snk) return flow;
    for (int &i = ptr[u]; i < g[u].size(); ++i) {
        edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
        int v = dir.v;
        if (h[v] != h[u] + 1)  continue;
        int inc = min(flow, dir.c - dir.f);
        inc = dfs(v, inc);
        if (inc) {
            dir.f += inc, rev.f -= inc;
            return inc;
        }
    }
    return 0;
}

int dinic () {
    int flow = 0;
    while (bfs()) {
        memset(ptr, 0, sizeof ptr);
        while (int inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}

int np, nr, c, x, sum;
int p[N], r[N];
vector <piii> edges;

bool ok (int k) {
    cl(h, 0);
    cl(ptr, 0);
    edgs.clear();
    for (int i = 0; i < N; i++) g[i].clear();
    for (int i = 1; i <= nr; i++) add_edge(src, i, r[i]);
    for (int i = 1; i <= np; i++) add_edge(i+M, snk, p[i]);
    for (auto e : edges) {
        int b = e.st;
        int a = e.nd.st;
        int w = e.nd.nd;
        if (w <= k) add_edge(a, b+M, INF);
    }
    int d = dinic();
    return d == sum;
}

int main () {
    scanf("%d%d%d", &np, &nr, &c);
    src = 0;
    snk = N-1;
    for (int i = 1; i <= np; i++) scanf("%d", &p[i]), sum += p[i];
    for (int i = 1; i <= nr; i++) scanf("%d", &r[i]);
    while (c--) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges.pb({a, {b, w}});
    }

    int l = 1, m, r = INF;
    while (l < r) {
        m = (l+r)/2;
        if (!ok(m)) l = m+1;
        else r = m;
    }

    printf("%d\n", ok(l) ? l : -1);

    return 0;
}
