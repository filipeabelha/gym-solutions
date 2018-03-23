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

int n, m, a, b, cnt, col[N], vis[N];
vi adj[N];
bool ok;

void dfs (int v) {
    if (vis[v]) return;
    vis[v] = 1;

    for (auto u : adj[v]) {
        if (col[u] == -1) col[u] = 1^col[v];
        else if (col[u] == col[v]) ok = false;
        dfs(u);
    }
}

int main () {
    while (~scanf("%d%d", &n, &m) and ++cnt) {
        cl(col, -1);
        cl(vis, 0);
        for (int i = 0; i < N; i++) adj[i].clear();
        ok = true;

        while (m--) {
            scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        col[1] = 0;
        dfs(1);
        printf("Instancia %d\n%s\n\n", cnt, ok ? "sim" : "nao");
    }
    return 0;
}
