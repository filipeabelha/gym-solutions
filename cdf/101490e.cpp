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

ll n, m, x;
ll a, b, t;

ll dist[N];
vector <pll> adj[N];
priority_queue <pll> pq;

ll maxi, ans;

vector <piii> edges;

void dijkstra() {
    cl(dist, 63);
    dist[1] = 0;
    pq.push(mp(0, 1));
    while (!pq.empty()) {
        ll ud = -pq.top().st;
        ll u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (pll x : adj[u]) {
            ll v = x.first;
            ll w = x.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(mp(-dist[v],v));
            }
        }
    }
}

bool slv (ll k) {
    for (int i = 0; i < N; i++) adj[i].clear();

    for (auto p : edges) {
        ll t = p.st;
        ll a = p.nd.st;
        ll b = p.nd.nd;
        if (t > k) break;
        adj[a].pb(mp(b, t));
        adj[b].pb(mp(a, t));
    }

    dijkstra();

    if (dist[n] == 4557430888798830399) return false;
    if (100*dist[n] > maxi) return false;
    return true;

}

int main () {
    scanf("%lld%lld%lld", &n, &m, &x);
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &a, &b, &t);
        adj[a].pb(mp(b, t));
        adj[b].pb(mp(a, t));
        edges.pb(mp(t, mp(a, b)));
    }

    sort(edges.begin(), edges.end());

    dijkstra();

    maxi = dist[n]*(100+x);;

    ll l = 1, m, r = INF;

    while (l < r) {
        m = (l+r)/2;
        if (!slv(m)) l = m+1;
        else r = m;
    }

    printf("%lld\n", l);
    return 0;
}
