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
const int N = 2e3+5;
const int M = 35;
const int INF = 1e9;

struct edge {int v, c, f;};

int src, snk, h[N], ptr[N];
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
        for (int i : g[u]) {
            int v = edgs[i].v;
            if (!h[v] and edgs[i].f < edgs[i].c)
                q.push(v), h[v] = h[u] + 1;
        }
    }
    return h[snk];
}

ll dfs (int u, ll flow) {
    if (!flow or u == snk) return flow;
    for (int &i = ptr[u]; i < g[u].size(); ++i) {
        edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
        int v = dir.v;
        if (h[v] != h[u] + 1)  continue;
        ll inc = min(flow, (ll) dir.c - dir.f);
        inc = dfs(v, inc);
        if (inc) {
            dir.f += inc, rev.f -= inc;
            return inc;
        }
    }
    return 0;
}

ll dinic() {
    ll flow = 0;
    while (bfs()) {
        memset(ptr, 0, sizeof ptr);
        while (ll inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}

int n, m, c;
char a[M][M];

int vin (int i, int j) {
    return 2*((i-1)*m + j);
}

int vout (int i, int j) {
    return 2*((i-1)*m + j) + 1;
}

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};
int cost[N];

int main () {
    scanf("%d%d%d", &m, &n, &c);
    snk = N-1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &a[i][j]);
        }
    }

    for (int i = 0; i < c; i++) scanf("%d", &cost[i]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'B') {
                add_edge(src, vin(i, j), INF);
            }

            int cst = INF;
            if (a[i][j] >= 'a' and a[i][j] <= 'z') cst = cost[a[i][j]-'a'];
            add_edge(vin(i, j), vout(i, j), cst);

            if (i == 1 or i == n or j == 1 or j == m) {
                add_edge(vout(i, j), snk, INF);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i+dx[k];
                int y = j+dy[k];
                if (x < 1 or x > n or y < 1 or y > m) continue;
                add_edge(vout(i, j), vin(x, y), INF);
            }
        }
    }

    ll ans = dinic();
    printf("%lld\n", ans < INF ? ans : -1);

    return 0;
}
