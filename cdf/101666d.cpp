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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll n, m, a, b, w;

ll dist[N];
vector <pll> adj[N];
priority_queue <pll> pq;
int vis[N], ori[N];

void dijkstra () {
    cl(dist, 63);
    dist[1] = 0;
    pq.push(mp(0, 1));

    while (!pq.empty()) {
        ll ud = -pq.top().st;
        ll u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]){
            ll v = x.st;
            ll w = x.nd;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                ori[v] = u;
                pq.push(mp(-dist[v], v));
            }
        }
    }
}

vector <ll> v;

int dfs (int x) {
    if (vis[x]) return 0;
    vis[x] = 1;
    v.pb(x);

    if (x == 0) return 1;

    for (auto p : adj[x]) {
        int y = p.st;
        if (x != ori[y] and dfs(y)) return 1;
    }

    vis[x] = 0;
    v.pop_back();
    return 0;

}


int main () {
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &a, &b, &w);
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }

    dijkstra();

    if (dfs(1)) {
        printf("%d ", (int) v.size());
        reverse(v.begin(), v.end());
        for (auto z : v) printf("%lld ", z); printf("\n");
    } else printf("impossible\n");
    return 0;
}
