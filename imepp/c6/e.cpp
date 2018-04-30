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
#define gcd(x, y) __gcd((x), (y))

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
const int N = 3e5+10;

ll dist[N], par[N], dpar[N];
vector <pll> adj[N];
priority_queue <pii> pq;
ll n1, n2, s, edges, n, strt;

map <pll, int> id;

void dijkstra () {
    for (int i = 1; i <= edges; i++) {
        scanf("%lld%lld%lld", &n1, &n2, &s);
        adj[n1].pb({n2,s});
        adj[n2].pb({n1,s});
        if (!id.count({n1, n2})) {
            id[{n1, n2}] = id[{n2, n1}] = i;
        }
    }
    scanf("%lld", &strt);
    cl(dist, 63);
    cl(dpar, 63);
    dist[strt] = dpar[strt] = 0;
    pq.push(mp(0,strt));
    while (!pq.empty()) {
        int ud = -pq.top().st;
        int u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            int v = x.st;
            int w = x.nd;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                par[v] = u;
                dpar[v] = w;
                pq.push(mp(-dist[v],v));
            } else if (dist[v] == dist[u] + w) {
                if (dpar[v] > w) {
                    dpar[v] = w;
                    par[v] = u;
                }
            }
        }
    }
}

int main () {
    scanf("%lld%lld", &n, &edges);
    dijkstra();

    set <int> s;
    ll cost = 0;
    for (int i = 1; i <= n; i++) {
        s.insert(id[{i, par[i]}]);
        s.insert(id[{par[i], i}]);
        cost += dpar[i];
    }
    if (s.count(0)) s.erase(0);
    printf("%lld\n", cost);
    for (auto x : s) printf("%d ", x); printf("\n");


    return 0;
}
