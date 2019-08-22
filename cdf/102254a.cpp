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
const int N = 2e3+10;

int dist[N];
vector <pii> adj[N];
priority_queue <pii> pq;
int a, b, n, m;

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


int main () {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb({b, 1});
        adj[b].pb({a, 1});
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        for (int j = 1; j <= n; j++) {
            if (i != j) ans = max(ans, dist[j]);
        }
    }
    if (ans == INF) printf("=[\n");
    else printf("=] %d\n", ans);

    return 0;
}
