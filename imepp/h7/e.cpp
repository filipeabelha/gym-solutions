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

int t, n, m, a, b, w, dist[N];
vector <pii> adj[N];

int main () {
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < N; i++) adj[i].clear();

        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &a, &b, &w);
            adj[a].pb({b, w});
        }

        cl(dist, 63);
        dist[0] = 0;
        int ok = 0;
        for (int k = 1; k <= n; k++) {
            for (int u = 0; u < n; u++) {
                for (auto p : adj[u]) {
                    int v = p.st;
                    int w = p.nd;
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        if (k == n) ok = 1;
                    }
                }
            }
        }

        printf("%spossible\n", ok ? "" : "not ");
    }
    return 0;
}
