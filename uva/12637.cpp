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
const int N = 2e2+10;
const int M = 1e2+3;
const int INF = 1e9;

struct edge {int v, f, w, c; };

int flw_lmt = INF, src, snk, flw, cst, p[N], d[N], et[N];
vector<edge> e;
vector<int> g[N];

void add_edge(int u, int v, int w, int c) {
    int k = e.size();
    g[u].push_back(k);
    g[v].push_back(k+1);
    e.push_back({ v, 0,  w, c });
    e.push_back({ u, 0, -w, 0 });
}

void clear() {
    src = 0;
    snk = N-1;
    flw_lmt = INF;
    for (int i = 0; i < N; i++) g[i].clear();
    e.clear();
}

void min_cost_max_flow() {
    flw = 0, cst = 0;
    while (flw < flw_lmt) {
        memset(et, 0, sizeof et);
        memset(d, 63, sizeof d);
        deque<int> q;
        q.push_back(src), d[src] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop_front();
            et[u] = 2;

            for(int i : g[u]) {
                edge &dir = e[i];
                int v = dir.v;
                if (dir.f < dir.c and d[u] + dir.w < d[v]) {
                    d[v] = d[u] + dir.w;
                    if (et[v] == 0) q.push_back(v);
                    else if (et[v] == 2) q.push_front(v);
                    et[v] = 1;
                    p[v] = i;
                }
            }
        }

        if (d[snk] > INF) break;

        int inc = flw_lmt - flw;
        for (int u = snk; u != src; u = e[p[u]^1].v) {
            edge &dir = e[p[u]];
            inc = min(inc, dir.c - dir.f);
        }

        for (int u = snk; u != src; u = e[p[u]^1].v) {
            edge &dir = e[p[u]], &rev = e[p[u]^1];
            dir.f += inc;
            rev.f -= inc;
            cst += inc * dir.w;
        }

        if (!inc) break;
        flw += inc;
    }
}

int xa[N], ya[N], xb[N], yb[N];

int main () {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        clear();
        memset(xa, 0, sizeof xa);
        memset(ya, 0, sizeof ya);
        memset(xb, 0, sizeof xb);
        memset(yb, 0, sizeof yb);

        for (int i = 1; i <= a; i++) {
            scanf("%d%d", &xa[i], &ya[i]);
            add_edge(src, i, 0, 1);
        }
        for (int i = 1; i <= b; i++) {
            scanf("%d%d", &xb[i], &yb[i]);
            add_edge(i+M, snk, 0, 1);
        }
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                add_edge(i, j+M, abs(xa[i]-xb[j]) + abs(ya[i]-yb[j]), 1);
            }
        }

        min_cost_max_flow();
        printf("%d\n", flw == b ? cst : -1);
    }

    return 0;
}
