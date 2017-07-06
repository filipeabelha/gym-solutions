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
const int N = 1e3+5;
const int K = 90;

int tc, n, x, y, vo[N], vn[N], w[N], dp[K][K];

int main () {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d%d", &x, &y, &n);
        for (int k = 0; k < n; k++) scanf("%d%d%d", &vo[k], &vn[k], &w[k]);
        cl(dp, 63);
        dp[0][0] = 0;
        for (int k = 0; k < n; k++) {
            for (int i = x; i >= 0; i--) {
                for (int j = y; j >= 0; j--) {
                    int ii = min(i+vo[k], x);
                    int jj = min(j+vn[k], y);
                    dp[ii][jj] = min(dp[ii][jj], dp[i][j]+w[k]);
                }
            }
        }
        printf("%d\n", dp[x][y]);
    }
    return 0;
}
