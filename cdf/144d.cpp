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

ll dist[N];
set <ll> par[N];
vector <pll> adj[N];
priority_queue <pll> pq;
ll a, b, w;
set <pair<pll, pll> > ok;

void dijkstra (ll s) {
    cl(dist, 63);
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        ll ud = -pq.top().st;
        ll u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            ll v = x.st;
            ll w = x.nd;
            if (dist[v] == dist[u] + w) {
                par[v].insert(u);
            }
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                par[v].clear();
                par[v].insert(u);
                pq.push({-dist[v], v});
            }
        }
    }
}

ll n, m, s, l, ans;

int main () {
    scanf("%lld%lld%lld", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld%lld", &a, &b, &w);
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
    dijkstra(s);
    scanf("%lld", &l);
    for (ll i = 1; i <= n; i++) if (dist[i] == l) ans++;
    for (ll u = 1; u <= n; u++) {
        for (auto x : adj[u]) {
            ll v = x.st;
            ll w = x.nd;
            if (par[u].count(v)) continue;
            if (dist[u] < l and dist[u] + w > l) {
                ll du = l-dist[u];
                ll dv = dist[u]+w-l;
                if (dist[v]+dv < dist[u]+du) continue;
                pair <pii, pii> p = {{u, v}, {du, dv}};
                if (p.st.st > p.st.nd) {
                    swap(p.st.st, p.st.nd);
                    swap(p.nd.st, p.nd.nd);
                }
                ok.insert(p);
            }
        }
    }
    ans += ok.size();
    printf("%lld\n", ans);
    return 0;
}
