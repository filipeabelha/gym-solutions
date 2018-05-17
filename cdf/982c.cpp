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

int n, a, b;
ll ans = -1;
int vis[N];
set <int> adj[N];

int dfs (int v) {
    if (vis[v]) return 0;
    vis[v] = 1;
    ll qty = 0;
    for (auto u : adj[v]) {
        qty += dfs(u);
    }
    ans += (qty&1);
    return qty+1;
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    dfs(1);
    printf("%lld\n", (n&1) ? -1 : ans);
    return 0;
}
