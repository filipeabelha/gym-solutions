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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

ll n, m, p[N], vis[N], dist[N];
vl adj[N], adjr[N];
set <ll> par[N];

int main () {
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++) {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        adj[u].pb(v);
        adjr[v].pb(u);
    }

    ll k;
    scanf("%lld", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%lld", &p[i]);
    }

    queue <pll> q;
    vis[p[k]] = 1;
    q.push({0, p[k]});

    while (q.size()) {
        ll d = q.front().st;
        ll v = q.front().nd;
        q.pop();

        for (auto u : adjr[v]) {
            if (!vis[u]) {
                vis[u] = 1;
                dist[u] = d+1;
                q.push({d+1, u});
            }
            if (dist[u] == d+1) par[u].insert(v);
        }
    }

    ll mn = 0, mx = 0;
    for (int i = 1; i < k; i++) {
        if (!par[p[i]].count(p[i+1])) mn++;
        if (par[p[i]].size() - par[p[i]].count(p[i+1]) > 0) mx++;

    }
    printf("%lld %lld\n", mn, mx);

    return 0;
}
