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
const int N = 1e2+5;

int n, x, e, dep[N], vis[N];
vi adj[N];

void dfs (int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto v : adj[u]) dfs(v);
}

int main () {
    while (~scanf("%d", &n) and n) {
        for (int i = 0; i < N; i++) adj[i].clear();
        cl(dep, 0);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            while (x--) {
                scanf("%d", &e);
                adj[i].pb(e);
            }
        }

        for (int i = 1; i <= n; i++) {
            cl(vis, 0);
            dfs(i);
            for (int j = 1; j <= n; j++) dep[i] += vis[j];
            dep[i]--;
        }

        int d = -1;
        int a = 0;
        for (int i = 1; i <= n; i++) if (d < dep[i]) {
            d = dep[i];
            a = i;
        }

        printf("%d\n", a);

    }
    return 0;
}
