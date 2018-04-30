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
const int N = 2e5+5;

vector <pll> adj[N];
ll n, m, dist[N];
priority_queue <pll> pq;

void dijkstra () {
    ll a, b, s;

    while (m--) {
        scanf("%lld%lld%lld", &a, &b, &s);
        adj[a].pb({b, 2*s});
        adj[b].pb({a, 2*s});
    }

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &s);
        adj[0].pb({i, s});
        adj[i].pb({0, s});
    }

    cl(dist, 63);
    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        ll ud = -pq.top().first;
        ll u = pq.top().second; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            ll v = x.first;
            ll w = x.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(mp(-dist[v],v));
            }
        }
    }
}


int main () {
    scanf("%lld%lld", &n, &m);
    dijkstra();
    for (int i = 1; i <= n; i++) printf("%lld%c", dist[i], " \n"[i==n]);
    return 0;
}
