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
const int N = 1e3+5;

int n, m, k, x, a, b, ans, pp;
vi v;
set <int> adj[N];
int vis[N], p, c;

void dfs (int u) {
    if (vis[u]) return;
    vis[u] = 1;
    p++;

    for (auto v : adj[u]) dfs(v);
}

int main () {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) scanf("%d", &x), v.pb(x);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (auto g : v) {
        p = 0;
        dfs(g);
        ans += p*(p-1)/2;
        pp = max(pp, p);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) c++;
    ans += (pp+c)*(pp+c-1)/2 - pp*(pp-1)/2;
    ans -= m;
    printf("%d\n", ans);
}
