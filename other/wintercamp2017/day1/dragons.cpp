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
const int N = 3e2+5;

int n, f, d;
int is, s, g;
int vis[N];
vector <pii> drag[N], dragnow;
vi adj[N];
ll ans;

int chk(int k) {
    ll sum = 0;
    for (auto p : dragnow) if (k <= p.nd) sum += p.st;
    return (k >= sum ? 1 : 0);
}

void dfs (int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto p : drag[u]) dragnow.pb(p);
    for (auto v : adj[u]) dfs(v);
}

int main () {
    scanf("%d%d%d", &n, &f, &d);
    for (int a, b, i = 0; i < f; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 0; i < d; i++) {
        scanf("%d%d%d", &is, &s, &g);
        drag[is].pb(mp(s, g));
    }
    for (int i = 0; i < n; i++) if (!vis[i]) {
        dragnow.clear();
        dfs(i);
        int l, m, r;
        l = 0; r = INF;
        while (l < r) {
            m = (l+r)/2;
            if (!chk(m)) l = m+1;
            else r = m;
        }
        m = (l+r)/2;
        ans += m;
    }
    printf("%lld\n", ans);
    return 0;
}
