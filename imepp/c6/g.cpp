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

ll par[N], sz[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}

ll w[N];

vector <piii> edges;

ll n, m, a, b;

int main () {
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;

    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &w[i]);

    while (m--) {
        scanf("%lld%lld", &a, &b);
        edges.pb({-min(w[a], w[b]), {a, b}});
    }

    ll ans = 0;
    sort(edges.begin(), edges.end());
    for (auto e : edges) {
        ll w = -e.st;
        ll u = e.nd.st;
        ll v = e.nd.nd;
        if (find(u) != find(v)) {
            ans += w*sz[find(u)]*sz[find(v)];
            unite(u, v);
        }
    }

    printf("%.6lf\n", (double) 2*ans/(n*(n-1)));


    return 0;
}
