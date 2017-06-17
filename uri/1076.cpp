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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e4+10;

int vis[N], tc, n, v, e, a, b, ans = -2;
vii adj(N);

void dfs (int x) {
    ans += 2;
    vis[x] = 1;
    for (auto i : adj[x]) if (!vis[i]) dfs(i);
}

int main () {
    scanf("%d", &tc); while (tc--) {
        scanf("%d%d%d", &n, &v, &e);
        for (int i = 0; i < e; i++) {
            scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs(n);
        printf("%d\n", ans);
        for (int i = 0; i < N; i++) adj[i].clear();
        cl(vis, 0);
        ans = -2;
    }
    return 0;
}
