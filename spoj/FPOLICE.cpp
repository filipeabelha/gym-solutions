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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e2+10;

int dist[N][N], risk[N][N], vis[N];
int tc, n, t, dans, rans;

void go (int u, int d, int r) {
    if (d > t) return;
    vis[u] = 1;
    if (u == n) {
        if      (dans > t or rans > r)   dans = d, rans = r;
        else if (dans > d and rans == r) dans = d, rans = r;
        vis[u] = 0;
        return;
    }
    for (int i = 1; i <= n; i++) {
        int dis = dist[u][i];
        int ris = risk[u][i];
        if (!vis[i] and i != u) go(i, d+dis, r+ris);
    }
    vis[u] = 0;
}

int main () {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &n, &t);
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &dist[i][j]);
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &risk[i][j]);
        cl(vis, 0);
        dans = rans = INF;
        go(1, 0, 0);
        dans <= t ? printf("%d %d\n", rans, dans) : printf("-1\n");
    }
    return 0;
}
