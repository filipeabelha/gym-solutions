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
typedef pair<ld, pii> T;

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

int t, n, w;
ld x[N], y[N];
ld a, b, ans;

vector <T> edges;

int main () {
    while (~scanf("%d", &n) and n) {

        for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
        ans = 0;
        edges.clear();

        for (int i = 1; i <= n; i++) scanf("%Lf%Lf", &x[i], &y[i]);

        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                ld dx = x[i]-x[j];
                ld dy = y[i]-y[j];
                ld w = sqrt(dx*dx + dy*dy);
                edges.pb({w, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());

        for (auto p : edges) {
            ld w = p.st;
            int a = p.nd.st;
            int b = p.nd.nd;
            if (find(a) == find(b)) continue;
            unite(a, b);
            ans = max(ans, w);
        }
        printf("%.4Lf\n", ans);
    }

    return 0;
}
