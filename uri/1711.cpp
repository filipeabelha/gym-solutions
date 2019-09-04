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

int vis[N], sum[N];
vector <pii> adj[N];
int a, b, w, n, m, x, sz, ans;

int dist[N];
priority_queue <pii> pq;

void dijkstra (int s) {
    cl(dist, 63);
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int ud = -pq.top().st;
        int u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            int v = x.st;
            int w = x.nd;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(mp(-dist[v],v));
            }
        }
    }
}


void dfs (int v, int p, int s) {
    vis[v] = 1;
    sum[v] = s;
    for (auto z : adj[v]) {
        int u = z.st;
        int w = z.nd;
        if (vis[u]) {
            if (u != p and vis[v]) {
                int cyc = sum[v]-sum[u]+w;
                if (cyc <= 0) continue;
                if (cyc >= sz) {
                    ans = min(ans, cyc+2*dist[u]);
                }
            }
        } else dfs(u, v, s+w);
    }

}

int q;

int main () {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < N; i++) adj[i].clear();
        cl(sum, 0);

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &w);
            adj[a].pb({b, w});
            adj[b].pb({a, w});
        }

        scanf("%d", &q);
        while (q--) {
            scanf("%d%d", &x, &sz);
            dijkstra(x);
            ans = INF;
            cl(vis, 0);
            dfs(x, x, 0);
            printf("%d\n", ans == INF ? -1 : ans);
        }
    }

    return 0;
}
