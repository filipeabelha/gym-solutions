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
const int M = 1e3;

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

void clr() {
    memset(h, 0, sizeof h);
    memset(ptr, 0, sizeof ptr);
    edgs.clear();
    for (int i = 0; i < N; i++) g[i].clear();
    src = 1;
    snk = N-1;
}

vector <pii> games;
int pts[N];
char t[N][N];

int main () {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        memset(pts, 0, sizeof pts);
        games.clear();

        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf(" %c", &t[i][j]);
                if (t[i][j] == '1') t[i][j] = '2', pts[i] += 2;
                if (t[i][j] == 'd') t[i][j] = '1', pts[i] += 1;
                if (t[i][j] == '.') if (j > i) games.pb({i, j});
            }
        }

        vi valid;

        for (int i = 1; i <= n; i++) {
            vi oponents;
            for (int j = 1; j <= n; j++) if (t[i][j] == '.') {
                oponents.pb(j);
                t[i][j] = '2';
                t[j][i] = '0';
                pts[i] += 2;
            }

            int mx = 0;
            for (int j = 1; j <= n; j++) mx = max(mx, pts[j]);

            if (pts[i] == mx) {
                clr();
                int gamecnt = 2;
                for (auto g : games) if (g.st != i and g.nd != i) {
                    add_edge(src, gamecnt, 2);
                    add_edge(gamecnt, g.st+M, 2);
                    add_edge(gamecnt, g.nd+M, 2);
                    gamecnt++;
                }
                for (int j = 1; j <= n; j++) {
                    add_edge(j+M, snk, pts[i]-pts[j]);
                }
                int ans = dinic();
                gamecnt -= 2;
                if (ans == 2*gamecnt) valid.pb(i);
            }

            for (auto j : oponents) {
                t[i][j] = '.';
                t[j][i] = '.';
                pts[i] -= 2;
            }
        }
        for (int i = 0; i < valid.size(); i++) {
            printf("%d%c", valid[i], " \n"[i+1==valid.size()]);
        }

    }
    return 0;
}
