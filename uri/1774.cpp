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
const int N = 70;

int par[N], sz[N], v, e, x, y, d;

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}


int main () {
    for (int i = 0 ; i < N; i++) par[i] = i, sz[i] = i;

    vector <piii> edges; //mp(dist, mp(node1, node2))

    scanf("%d%d", &v, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d%d%d", &x, &y, &d);
        edges.pb(mp(d, mp(x, y)));
    }

    int cost = 0;
    sort(edges.begin(), edges.end());
    for (auto e : edges)
         if (find(e.nd.st) != find(e.nd.nd))
              unite(e.nd.st, e.nd.nd), cost += e.st;

    printf("%d\n", cost);

    return 0;
}
