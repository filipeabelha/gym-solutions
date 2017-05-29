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

const int INF = 0x3f3f3f3f, MOD = 1e9+ 7, EPS = 1e-6, N = 2e5+10;

int vert, edg, par[N], sz[N], x, y, z, ans;

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}

int main () {
    while (1) {
        scanf("%d%d", &vert, &edg);
        if (!vert and !edg) break;
        ans = 0; cl(sz, 0);
        for (int i = 0; i < N; i++) par[i] = i;
        vector<piii> edges;
        while (edg--) scanf("%d%d%d", &x, &y, &z), edges.pb(mp(z,mp(x, y))), ans += z;
        sort(edges.begin(), edges.end());
        for (auto e : edges)
            if (find(e.nd.st) != find(e.nd.nd))
                unite(e.nd.st, e.nd.nd), ans -= e.st;
        printf("%d\n", ans);
    }
    return 0;
}
