#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int par[N], sz[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}

int cost, t, n, m, a, b;
vector <pii> edges;

int main () {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        while (m--) {
            scanf("%d%d", &a, &b);
            edges.pb({a, b});
        }
        for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
        sort(edges.begin(), edges.end());
        for (auto e : edges)
            if (find(e.st) != find(e.nd))
                unite(e.st, e.nd), cost++;
        printf("%d\n", cost);

        edges.clear();
        cost = 0;
    }
    return 0;
}
