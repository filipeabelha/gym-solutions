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
const int N = 1e6+5;

int n, p;
int c[N], ans[N];
vi adj[N];
set <int> colors[N];

void dfs (int v) {
    colors[v].insert(c[v]);
    for (auto u : adj[v]) {
        dfs(u);
        if (colors[u].size() > colors[v].size())
            swap(colors[u], colors[v]);
        for (auto x : colors[u]) colors[v].insert(x);
    }
    ans[v] = colors[v].size();
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &p, &c[i]);
        adj[p].pb(i);
    }
    dfs(0);
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i==n]);
    return 0;
}
