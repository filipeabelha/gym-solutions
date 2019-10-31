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
const int N = 2e3+5;

struct edge {int v, c, f;};

int n, src, snk, h[N], ptr[N];
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

int dinic() {
    int flow = 0;
    while (bfs()) {
        memset(ptr, 0, sizeof ptr);
        while (int inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}


int pp, rr, cc, x;

int p[N], r[N];
vector <piii> arestas;

int idr (int i) {
    return i+1;
}

int idp (int i) {
    return i+rr+1;
}

bool solve (int k) {
    cl(h, 0);
    cl(ptr, 0);
    for (int i = 0; i < N; i++) g[i].clear();
    edgs.clear();

    src = 1;
    snk = N-1;

    int sum = 0;

    for (int i = 1; i <= pp; i++) {
        add_edge(idp(i), snk, p[i]);
        sum += p[i];
    }

    for (int i = 1; i <= rr; i++)
        add_edge(src, idr(i), r[i]);

    for (auto elem : arestas) {
        int t = elem.st;
        int a = elem.nd.st;
        int b = elem.nd.nd;
        if (t > k) break;
        add_edge(idr(b), idp(a), INF);
    }

    return (dinic() == sum);
}

int main () {
    src = 1;
    snk = N-1;

    scanf("%d%d%d", &pp, &rr, &cc);
    for (int i = 1; i <= pp; i++) scanf("%d", &p[i]);
    for (int i = 1; i <= rr; i++) scanf("%d", &r[i]);

    while (cc--) {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        arestas.pb({t, {a, b}});
    }

    sort(arestas.begin(), arestas.end());

    int lo = 0, mi, hi = INF;
    while (lo < hi) {
        mi = (lo+hi)/2;
        if (!solve(mi)) lo = mi+1;
        else hi = mi;
    }

    printf("%d\n", lo == INF ? -1 : lo);

    return 0;
}
