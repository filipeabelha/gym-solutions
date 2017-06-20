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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 5e2+10;

int age[N], pos[N], vis[N];
int v, e, ins;
int a, b, ans;
char chr;
vii adj(N);

void go (int u) {
    vis[u] = 1;
    if (u != pos[a]) ans = min(ans, age[u]);
    for (int v : adj[u]) if (!vis[v]) go(v);
}

int main () {
    while (~scanf("%d%d%d", &v, &e, &ins)) {
        for (int i = 1; i < N; i++) adj[i].clear();
        for (int i = 1; i < N; i++) pos[i] = i;

        for (int i = 1; i <= v; i++) scanf("%d", &age[i]);
        for (int i = 1; i <= e; i++) {
            scanf("%d%d", &a, &b);
            adj[b].pb(a);
        }
        for (int i = 1; i <= ins; i++) {
            scanf("%c%c", &chr, &chr);
            if (chr == 'T') {
                scanf("%c%d%c%d", &chr, &a, &chr, &b);
                swap(age[pos[a]], age[pos[b]]);
                swap(pos[a], pos[b]);
            } else if (chr == 'P') {
                cl(vis, 0);
                scanf("%c%d", &chr, &a);
                ans = INF;
                go(pos[a]);
                ans == INF ? printf("*\n") : printf("%d\n", ans);
            }
        }
    }
    return 0;
}
