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

int n, m, z;
vi adj[N];

int b[N], vis[N], ans, x;

bool match (int u) {
    if (vis[u] == x) return 0;
    vis[u] = x;
    for (auto v : adj[u])
        if (!b[v] or match(b[v])) return b[v] = u;
    return false;
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        while (1) {
            scanf("%d", &z);
            if (!z) break;
            adj[i].pb(z);
        }
    }
    for (int i = 1; i <= n; i++) x++, ans += match(i);
    printf("%d\n", ans);
    for (int i = 1; i <= m; i++) if (b[i]) printf("%d %d\n", b[i], i);
    return 0;
}
