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
const int N = 2e5+5;

int n, m;
vector <pll> adj[N];
ll x, y, w;

int vis[N];
priority_queue <pll> pq;
ll a[N];

int main () {
    cl(ans, 63);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &x, &y, &w);
        adj[x].pb(mp(y, w));
        adj[y].pb(mp(x, w));
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        pq.push(mp(-a[i], i));
    }

    while (!pq.empty()) {
        ll k = -pq.top().st;
        ll u = pq.top().nd; pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        ans[u] = a[u];

        for (auto p : adj[u]) {
            ll v = p.st;
            ll w = p.nd;
            ll d = 2*w + a[u];
            a[v] = min(a[v], d);
            pq.push(mp(-a[v], v));
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%lld%c", a[i], " \n"[i==n]);
    return 0;
}
