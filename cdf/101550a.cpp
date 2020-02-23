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
const int Q = 1e4+5;
const int NN = 1e6+5;

int step[N][N], ok[N][N], ans[Q];
vector <pii> v[Q];
int n, m, q;

int id (int x, int y) {
    return (x-1)*m + y;
}

int par[NN], sz[NN], cnt;

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    cnt--;
}

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

int main () {
    for (int i = 0; i < NN; i++) par[i] = i, sz[i] = 1;

    scanf("%d%d%d", &n, &m, &q);
    cl(step, 63);

    for (int k = 0; k < q; k++) {
        int xa, ya, xb, yb;
        scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
        if (xa == xb) {
            int i = xa;
            for (int j = min(ya, yb); j <= max(ya, yb); j++) {
                step[i][j] = min(step[i][j], k);
            }
        } else if (ya == yb) {
            int j = ya;
            for (int i = min(xa, xb); i <= max(xa, xb); i++) {
                step[i][j] = min(step[i][j], k);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (step[i][j] == INF) step[i][j] = q;
            v[step[i][j]].pb({i, j});
        }
    }

    for (int k = q; k > 0; k--) {
        for (auto p : v[k]) {
            int x = p.st;
            int y = p.nd;
            cnt++;
            ok[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int X = x+dx[i];
                int Y = y+dy[i];
                if (X < 1 or X > n) continue;
                if (Y < 1 or Y > m) continue;
                if (!ok[X][Y]) continue;
                unite(id(x, y), id(X, Y));
            }
        }
        ans[k] = cnt;
    }

    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
