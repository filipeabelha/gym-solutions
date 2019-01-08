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

ll n, a[N][3], dp[N][3];

int main () {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) scanf("%lld", &a[i][j]);
        dp[i][1] = a[i][1] + max(dp[i-1][2], dp[i-1][3]);
        dp[i][2] = a[i][2] + max(dp[i-1][1], dp[i-1][3]);
        dp[i][3] = a[i][3] + max(dp[i-1][1], dp[i-1][2]);
    }
    printf("%lld\n", max(dp[n][1], max(dp[n][2], dp[n][3])));
    return 0;
}
