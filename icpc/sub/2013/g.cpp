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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e2+5;
const int M = 1e5+5;

int n, m, lin[M], col[M], g[N][N], ans;

void swlines (int x, int y) {
    if (x == y) return;
    ans++;
    for (int j = 1; j <= m; j++) {
        int& a = g[x][j];
        int& b = g[y][j];
        swap(lin[a], lin[b]);
        swap(a, b);
    }
}

void swcols (int x, int y) {
    if (x == y) return;
    ans++;
    for (int i = 1; i <= n; i++) {
        int& a = g[i][x];
        int& b = g[i][y];
        swap(col[a], col[b]);
        swap(a, b);
    }
}

int main () {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &g[i][j]);
            lin[g[i][j]] = i;
            col[g[i][j]] = j;
        }
    }

    for (int x = 1; x <= m; x++) swcols(x, col[x]);
    for (int x = 1; x <= n*m; x += m) swlines((x-1)/m+1, lin[x]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] != (i-1)*m + j) {
                printf("*\n");
                return 0;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
