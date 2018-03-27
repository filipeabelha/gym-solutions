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
const int N = 1e3+5;

int n, k, d;
ll dp[N][2];

int main () {
    scanf("%d%d%d", &n, &k, &d);
    dp[0][0] = 1;
    for (int i = 0; i < N/2; i++) {
        for (int j = 1; j < d; j++) {
            dp[i+j][0] += dp[i][0];
            dp[i+j][0] %= MOD;

            dp[i+j][1] += dp[i][1];
            dp[i+j][1] %= MOD;
        }
        for (int j = d; j <= k; j++) {
            dp[i+j][1] += dp[i][0] + dp[i][1];
            dp[i+j][1] %= MOD;
        }
    }
    printf("%lld\n", dp[n][1]);
    return 0;
}
