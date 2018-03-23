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
const int K = 1e4+5;

int n, x, y, vis[N][2], ans = -1;
vi adj[N][2];
set <int> xx;

void dfs (int v, int i) {
    if (vis[v][i]) return;
    vis[v][i] = 1;
    for (auto u : adj[v][i]) dfs(u, i^1);
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        xx.insert(x);
        adj[x][0].pb(y);
        adj[y][1].pb(x);
    }
    for (auto x : xx) if (!vis[x][0]) dfs(x, 0), ans++;
    printf("%d\n", ans);
    return 0;
}
