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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

const int N = 5e2+10;

int tc, n, x, y;
int par[N], sz[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]);}

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}

int dist (int x1, int x2, int y1, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main () {
    scanf("%d", &tc); while (tc--) {
        scanf("%d", &n);
        vi vx, vy;
        vx.pb(0); vy.pb(0);
        for (int i = 0 ; i < N; i++) par[i] = i, sz[i] = i;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &x, &y);
            vx.pb(x);
            vy.pb(y);
        }

        vector <piii> edges; //mp(dist, mp(node1, node2))

        for (int i = 1; i <= n; i++) for (int j = i+1; j <= n; j++)
            edges.pb(mp(dist(vx[i], vx[j], vy[i], vy[j]), mp(i, j)));

        double cost = 0;

        sort(edges.begin(), edges.end());
        for (auto e : edges)
            if (find(e.nd.st) != find(e.nd.nd))
                unite(e.nd.st, e.nd.nd), cost += sqrt(e.st)/100;

        printf("%.2lf\n", cost);
    }
    return 0;
}
