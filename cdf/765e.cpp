#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

int n, a, b, inc[N], vis[N];
vi adj[N], val[N];
queue <int> q;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n-1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
        inc[a]++;
        inc[b]++;
    }

    for (int i = 1; i <= n; i++) if (inc[i] <= 1) {
        q.push(i);
        val[i].pb(1);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 1;
        for (int v : adj[u]) {
            if (inc[v] > 1 and --inc[v] <= 1) {
                q.push(v);
            }
            if (vis[v]) {
                int ok = 1;
                for (auto k : val[v]) {
                    if      (val[u].size() == 0)                      val[u].pb(k+1);
                    else if (val[u].size() == 1 and val[u][0] != k+1) val[u].pb(k+1);
                    else if (val[u].size() == 2 and val[u][0] != k+1 and val[u][1] != k+1) {
                        printf("-1\n");
                        return 0;
                    }
                }
                if (val[v].size() >= 2) {
                    printf("-1\n");
                    return 0;
                }
                val[v].clear();
            }
        }
        if (q.empty()) {
            if (val[u].size() > 2) printf("-1\n");
            else {
                int ans = 0;
                for (auto k : val[u]) ans += k-1;
                while (ans % 2 == 0) ans /= 2;
                printf("%d\n", ans);
            }
        }
    }

    return 0;
}
