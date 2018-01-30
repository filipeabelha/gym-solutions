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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e2+5;
const int M = 2e4+5;

int x, n, k, p, b[N], c[N], ans[N], dp[N][M], qt[N][M];

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    scanf("%d", &k);

    cl(dp, 63);
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++)
            dp[i][j] = dp[i-1][j];

        for (x = 1; x <= c[i]; c[i] -= x, x *= 2)
            for (int j = k; j >= x*b[i]; j--)
                if (dp[i][j] > dp[i][j-x*b[i]] + x)
                    dp[i][j] = dp[i][j-x*b[i]] + x,
                    qt[i][j] = qt[i][j-x*b[i]] + x;

        x = c[i];
        if (x) for (int j = k; j >= x*b[i]; j--)
            if (dp[i][j] > dp[i][j-x*b[i]] + x)
                dp[i][j] = dp[i][j-x*b[i]] + x,
                qt[i][j] = qt[i][j-x*b[i]] + x;

    }

    int j = k;
    for (int i = n; i > 0; i--) {
        ans[i] += qt[i][j];
        j -= qt[i][j]*b[i];
    }

    printf("%d\n", dp[n][k]);
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i==n]);
    return 0;
}
