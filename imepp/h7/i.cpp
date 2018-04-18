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

int par[N], sz[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

int t, n, m, a, b, w;

vector <piii> edges;

int main () {
    while (~scanf("%d%d", &n, &m) and n and m and ++t) {
        printf("Teste %d\n", t);

        for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;

        edges.clear();
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &a, &b, &w);
            edges.pb({w, {a, b}});
        }

        sort(edges.begin(), edges.end());

        for (auto p : edges) {
            int w = p.st;
            int a = p.nd.st;
            int b = p.nd.nd;
            if (find(a) == find(b)) continue;
            unite(a, b);
            if (a > b) swap(a, b);
            printf("%d %d\n", a, b);
        }
        printf("\n");
    }

    return 0;
}
