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
const int S = 1e2+5;

int n, m, k, s;
int a[N], d[N][S], vis[N];
vi adj[N];

int main () {
    scanf("%d%d%d%d", &n, &m, &k, &s);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cl(d, 63);

    for (int i = 1; i <= k; i++) {
        queue <pii> q;
        cl(vis, 0);
        for (int j = 1; j <= n; j++) if (a[j] == i) {
            q.push({j, 0});
            vis[j] = 1;
            d[j][i] = 0;
        }
        while (q.size()) {
            int v = q.front().st;
            int w = q.front().nd; q.pop();
            d[v][i] = min(d[v][i], w);
            for (auto u : adj[v]) if (!vis[u]) {
                vis[u] = 1;
                q.push({u, d[v][i]+1});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        sort(d[i]+1, d[i]+1+k);
        ll ans = 0;
        for (int z = 1; z <= s; z++) ans += d[i][z];
        printf("%lld%c", ans, " \n"[i==n]);
    }

    return 0;
}
