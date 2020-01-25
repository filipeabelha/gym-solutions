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
const int N = 1e5+5;

int n, a, b, vis[N];
vi ans, adj[N];

void dfs (int v) {
    if (vis[v]) return;
    vis[v] = 1;

    for (auto u : adj[v]) dfs(u);

    if (adj[v].size() == 1) ans.pb(v);
}

int main () {
    scanf("%d%*d", &n);
    for (int i = 0; i < n-1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0);

    int n = ans.size();
    printf("%d\n", (n+1)/2);
    for (int i = 0; i < (n+1)/2; i++)
        printf("%d %d\n", ans[i], ans[i+n/2]);

    return 0;
}
