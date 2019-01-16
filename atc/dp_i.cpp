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
const int N = 3e3+5;

int n;
ld p[N], dp[N][N], ans;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%Lf", &p[i]);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0]*(1-p[i]);
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1-p[i]);
        }
    }
    for (int j = n; 2*j > n; j--) ans += dp[n][j];
    printf("%.10Lf\n", ans);
    return 0;
}
