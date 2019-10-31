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

struct edge {int v, c, f;};

int n, src, snk, h[N], ptr[N];
vector <edge> edgs;
vector <int> g[N];

void add_edge (int u, int v, int c) {
    int k = edgs.size();
    edgs.pb({v, c, 0});
    edgs.pb({u, 0, 0});
    g[u].push_back(k);
    g[v].push_back(k+1);
}

bool bfs() {
    memset(h, 0, sizeof h);
    queue <int> q;
    h[src] = 1;
    q.push(src);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int i : g[u]) {
            int v = edgs[i].v;
            if (!h[v] and edgs[i].f < edgs[i].c)
                q.push(v), h[v] = h[u]+1;
        }
    }
    return h[snk];
}

int dfs (int u, int flow) {
    if (!flow or u == snk) return flow;
    for (int &i = ptr[u]; i < g[u].size(); i++) {
        edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
        int v = dir.v;
        if (h[v] != h[u] + 1) continue;
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

int m, k;
string r, s, t;
map <char, int> freq;
set <int> letters;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    src = 1;
    snk = N-1;

    cin >> m;
    for (int i = 0+150; i < m+150; i++) {
        freq.clear();
        cin >> r >> s >> t;
        for (auto c : r) freq[c]++;
        for (auto c : s) freq[c]++;
        for (auto c : t) freq[c]++;
        vector <pii> v;
        for (auto p : freq) {
            v.pb({p.nd, p.st});
        }
        sort(v.begin(), v.end());
        int z = v.back().st;
        for (auto p : v) {
            if (p.st == z) {
                add_edge(p.nd, i, 1);
                letters.insert(p.nd);
            }
        }
        add_edge(i, snk, 1);
    }
    cin >> k;
    for (auto c : letters) {
        add_edge(src, c, k);
    }
    cout << dinic() << endl;
    return 0;
}
