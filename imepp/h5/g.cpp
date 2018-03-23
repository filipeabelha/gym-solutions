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
const int N = 1e4+5;

int n, a, b, vis[N];
vi adj[N];
queue <pii> q;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int vv = 0;
    int dd = 0;
    vis[1] = 1;
    q.push({1, 0});
    while (q.size()) {
        pii p = q.front(); q.pop();
        int v = p.st;
        int d = p.nd;
        if (dd < d) {
            dd = d;
            vv = v;
        }
        for (auto u : adj[v]) if (!vis[u]) {
            vis[u] = 1;
            q.push({u, d+1});
        }
    }

    cl(vis, 0);
    int ans = 0;
    vis[vv] = 1;
    q.push({vv, 0});
    while (q.size()) {
        pii p = q.front(); q.pop();
        int v = p.st;
        int d = p.nd;
        ans = max(ans, d);

        for (auto u : adj[v]) if (!vis[u]) {
            vis[u] = 1;
            q.push({u, d+1});
        }
    }

    printf("%d\n", ans);
    return 0;
}
