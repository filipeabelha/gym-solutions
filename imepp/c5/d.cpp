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

int t, n, m, a, b, cnt, clr[N], vis[N];
vi adj[N];
bool ok;

void dfs (int v) {
    if (vis[v]) return;
    vis[v] = 1;

    for (auto u : adj[v]) {
        if (clr[u] == -1) clr[u] = clr[v]^1;
        else if (clr[u] == clr[v]) ok = false;
        dfs(u);
    }
}

int main () {
    scanf("%d", &t);
    while (t-- and ++cnt) {
        for (int i = 0; i < N; i++) adj[i].clear();
        cl(clr, -1);
        cl(vis, 0);
        ok = true;

        scanf("%d%d", &n, &m);
        while (m--) {
            scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }

        for (int i = 1; i <= n; i++) if (!vis[i]) {
            clr[i] = 0;
            dfs(i);
        }

        printf("Scenario #%d:\n", cnt);
        printf("%suspicious bugs found!\n", ok ? "No s" : "S");
    }
    return 0;
}
