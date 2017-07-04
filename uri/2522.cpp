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

int n, x[N], y[N], par[N];

double dist (int a, int b) {
    return hypot(x[a]-x[b], y[a]-y[b]);
}

int find (int k) {
    return (par[k] == k ? k : par[k] = find(par[k]));
}

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    par[b] = a;
}

int main () {
    while (~scanf("%d", &n)) {
        vector <pair <double, pii> > edges;
        for (int i = 0; i < N; i++) par[i] = i;
        for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
        for (int i = 1; i <= n; i++) for (int j = i+1; j <= n; j++)
            edges.pb(mp(dist(i, j), mp(i, j)));
        sort(edges.begin(), edges.end());
        double cost = 0;
        for (auto p : edges) {
            double d = p.st;
            int x = p.nd.st;
            int y = p.nd.nd;
            if (find(x) == find(y)) continue;
            unite(x, y);
            cost += d;
        }
        printf("%.2lf\n", cost);
    }
    return 0;
}
