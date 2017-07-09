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
const int N = 1e2+5;

int col[N], vis[N], ok;
vi adj[N];
int n, m, cnt;

void dfs (int u) {
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (col[v] == col[u]) ok = 0;
        col[v] = 1-col[u];
        if (!vis[v]) dfs(v);
    }
}

int main () {
    while (~scanf("%d%d", &n, &m) and ++cnt) {
        cl(col, -1);
        cl(vis, 0);
        for (int i = 0; i < N; i++) adj[i].clear();
        for (int a, b, i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        ok = 1;
        col[1] = 0;
        dfs(1);
        printf("Instancia %d\n", cnt);
        printf("%s\n\n", ok ? "sim" : "nao");
    }
    return 0;
}
