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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll ans, cost, c[N];
int n, m, vis[N], a, b;
vi adj[N];

void dfs (int u) {
    vis[u] = 1;
    cost = min(cost, c[u]);
    for (auto v : adj[u]) if (!vis[v]) dfs(v);
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
    while (m--) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        cost = INF;
        if (!vis[i]) {
            dfs(i);
            ans += cost;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
