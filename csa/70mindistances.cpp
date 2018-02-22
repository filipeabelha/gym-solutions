#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 1e7, MOD = 1e9+7;
const int N = 1e2+5;

int n, m;

int dist[N];
vector <pii> adj[N];
priority_queue <pii> pq;

void dijkstra (int strt) {
    cl(dist, 63);
    dist[strt] = 0;
    pq.push(mp(0,strt));
    while (!pq.empty()) {
        int ud = -pq.top().first;
        int u = pq.top().second; pq.pop();
        if (dist[u] < ud) continue;
        for (pii x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(mp(-dist[v],v));
            }
        }
    }
}

int par[N], sz[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}

vector <piii> ans;
int a, b, t, ok = 1;

int main () {

    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &t);
        dijkstra(a);
        if (dist[b] < t) ok = 0;
        if (dist[b] >= t) {
            adj[a].pb(mp(b, t));
            adj[b].pb(mp(a, t));
            unite(a, b);
        }
    }
    if (!ok) printf("-1\n");
    else {
        for (int i = 2; i <= n; i++) {
            if (find(i) != find(1)) {
                unite(i, 1);
                adj[i].pb(mp(1, INF));
                adj[1].pb(mp(i, INF));
            }
        }
        for (int i = 1; i <= n; i++) {
            for (auto p : adj[i]) {
                if (p.st > i) ans.pb(mp(p.nd, mp(i, p.st)));
            }
        }
        printf("%d\n", (int) ans.size());
        for (auto p : ans) printf("%d %d %d\n", p.nd.st, p.nd.nd, p.st);
    }
    return 0;
}
