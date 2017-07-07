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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 5e2+5;

int tc, n, m;
int cyc, ans;
int vis[N], dis[N];
vii adj(N);
queue <pii> q;

int main () {
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        for (int i = 0; i < N; i++) adj[i].clear();
        ans = INF;
        scanf("%d%d", &n, &m);
        for (int a, b, i = 0; i < m; i++) {
            scanf("%d%d", &a, &b); a++; b++;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        for (int i = 1; i <= n; i++) {
            cl(vis, 0);
            cl(dis, 0);
            cyc = INF;
            q.push(mp(i, i));
            vis[i] = 1;
            while (!q.empty()) {
                int u = q.front().st;
                int s = q.front().nd;
                q.pop();
                for (auto v : adj[u]) {
                    if (vis[v] and v != s) cyc = min(cyc, dis[u]+dis[v]+1);
                    if (!vis[v]) {
                        q.push(mp(v, u));
                        vis[v] = 1;
                        dis[v] = dis[u]+1;
                    }
                }
            }
            ans = min(ans, cyc);
        }
        printf("Case %d: ", t);
        (ans == INF ? puts("impossible") : printf("%d\n", ans));
    }
    return 0;
}
