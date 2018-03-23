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

int n, m, x, p, a, b, cnt, vis[N];
vi adj[N], ans;
queue <pii> q;

int main () {
    while (~scanf("%d%d%d%d", &n, &m, &x, &p) and n and m and x and p and ++cnt) {
        cl(vis, 0);
        ans.clear();
        for (int i = 0; i < N; i++) adj[i].clear();

        while (m--) {
            scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }

        q.push({x, 0});
        vis[x] = 1;

        while (q.size()) {
            pii P = q.front(); q.pop();
            int v = P.st;
            int d = P.nd;

            if (d > 0 and d <= p) ans.pb(v);

            for (auto u : adj[v]) if (!vis[u]) {
                q.push({u, d+1}); vis[u] = 1;
            }
        }

        printf("Teste %d\n", cnt);
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            printf("%d%c", ans[i], " \n"[i+1==ans.size()]);
        printf("\n");
    }
    return 0;
}
