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
const int N = 1e5+5;

int tc, v, e, a, b;
int vis[N];
set <int> adj[N];

void dfs (int u, int dep) {
    vis[u] = 1;
    for (auto w : adj[u]) {
        for (int i = 0; i < 2*(dep+1); i++) printf(" ");
        printf("%d-%d", u, w);
        if (!vis[w]) {
            printf(" pathR(G,%d)\n", w);
            dfs(w, dep+1);
        } else printf("\n");;
    }
}

int main () {
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        cl(vis, 0);
        for (int i = 0; i < N; i++) adj[i].clear();

        scanf("%d%d", &v, &e);
        while (e--) {
            scanf("%d%d", &a, &b);
            adj[a].insert(b);
        }
        printf("Caso %d:\n", t);
        for (int i = 0; i < v; i++) if (!vis[i]) {
            dfs(i, 0);
            if (!adj[i].empty()) printf("\n");
        }
    }
    return 0;
}
