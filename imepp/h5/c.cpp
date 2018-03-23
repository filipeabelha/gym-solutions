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
const int N = 2e3+5;

int n, m, a, b, k, vis[N];
vi adj[N];

void dfs (int v) {
    if (vis[v]) return;
    vis[v] = 1;
    for (auto u : adj[v]) dfs(u);
}

int main () {
    while (~scanf("%d", &n) and n) {
        for (int i = 0; i < N; i++) adj[i].clear();

        scanf("%d", &m);
        while (m--) {
            scanf("%d%d%d", &a, &b, &k);
            adj[a].pb(b);
            if (k == 2) adj[b].pb(a);
        }
        dfs(1);

        int ok = 1;
        for (int r = 1; r <= n; r++) {
            cl(vis, 0);
            dfs(r);
            for (int i = 1; i <= n; i++) if (!vis[i]) ok = 0;
        }
        printf("%d\n", ok ? 1 : 0);
    }
    return 0;
}
