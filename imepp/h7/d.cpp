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
const int N = 1e5+5;

ll n, m, a, b, w, dist[N];
vector <pll> adj[N];
priority_queue <pll> pq;

int main () {
    scanf("%lld%lld", &n, &m);

    for (int i = 0; i < N; i++) adj[i].clear();

    while (m--) {
        scanf("%lld%lld%lld", &a, &b, &w);
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    cl(dist, 63);
    dist[0] = 0;
    pq.push({0, 0});

    while (pq.size()) {
        ll ud = -pq.top().st;
        ll u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto p : adj[u]) {
            ll v = p.st;
            ll w = p.nd;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }

    printf("%lld\n", dist[n+1]);

    return 0;
}
