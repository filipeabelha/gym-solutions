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

ll n, val[N], dist[N], prod[N];
ll sumdist[N], sumval[N], sumprod[N];
ll sub[N], vis[N], ans[N];
vector <pll> adj[N];

void dfs (ll v) {
    sub[v] = 1;
    sumval[v] = val[v];

    for (auto p : adj[v]) {
        ll u = p.st;
        ll w = p.nd;
        if (!vis[u]) {
            vis[u] = 1;
            dist[u] = dist[v] + w;
            prod[u] = val[u]*dist[u];
            dfs(u);
            sumdist[v] += sumdist[u] + dist[u];
            sumprod[v] += sumprod[u] + prod[u];
            sub[v] += sub[u];
            sumval[v] += sumval[u];
        }
    }
}

void dfs2 (ll v) {
    for (auto p : adj[v]) {
        ll u = p.st;
        ll w = p.nd;
        if (vis[u]) {
            vis[u] = 0;
            sumdist[u] = sumdist[v] + w*(n-2*sub[u]);
            sumprod[u] = sumprod[v] - w*sumval[u] + w*(sumval[1]-sumval[u]);
            dfs2(u);
        }
    }

    ans[v] = val[v]*sumdist[v] + sumprod[v];
}

int main () {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &val[i]);
    for (int i = 0; i < n-1; i++) {
        ll a, b, w;
        scanf("%lld%lld%lld", &a, &b, &w);
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    vis[1] = 1; dfs(1);
    vis[1] = 0; dfs2(1);

    for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);

    return 0;
}
