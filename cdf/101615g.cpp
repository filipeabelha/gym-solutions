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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int n, m, k, s, t, vis[N];
vector <piii> adj[N];
vi u, v;
map <int, bool> ok;

void dfs (int v, int e) {
    if (vis[v]) return;
    vis[v] = 1;

    for (auto p : adj[v]) {
        int u = p.st;
        int l = p.nd.st;
        int r = p.nd.nd;
        if (l <= e and e <= r) dfs(u, e);
    }
}

int main () {
    scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
    while (m--) {
        int a, b, l, r;
        scanf("%d%d%d%d", &a, &b, &l, &r);
        adj[a].pb({b, {l, r}});

        v.pb(l-1);
        v.pb(l);
        v.pb(r-1);
        v.pb(r);

        u.pb(l);
        u.pb(r);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());

    for (auto x : v) {
        cl(vis, 0);
        dfs(s, x);
        if (vis[t]) ok[x] = 1;
    }

    int ans = 0;
    for (int i = 0; i < u.size(); i++) {
        int x = u[i];
        ans += ok[x];
        if (i > 0 and ok[x-1]) {
            int y = u[i-1];
            ans += (x-y-1);
        }
    }

    printf("%d\n", ans);

    return 0;
}
