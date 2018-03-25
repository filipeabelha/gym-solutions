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
const int N = 55;

int n, m, ok = 1;
char t[N][N];

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &t[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (t[i][j] == '#') {
            vi lin, col;
            for (int k = 1; k <= n; k++) if (k != i and t[k][j] == '#') lin.pb(k);
            for (int k = 1; k <= m; k++) if (k != j and t[i][k] == '#') col.pb(k);
            for (auto a : lin) for (auto b : col) {
                if (t[a][b] != '#') ok = 0;
            }
        }
    }
    printf("%s\n", ok ? "Yes" : "No");
    return 0;
}
