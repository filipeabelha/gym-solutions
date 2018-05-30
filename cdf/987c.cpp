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

ll n;
ll s[N], c[N];
ll dp[N][10];

int main () {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &s[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);

    cl(dp, 63);
    for (int i = 1; i <= n; i++) dp[i][1] = c[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (s[i] > s[j]) {
                dp[i][2] = min(dp[i][2], dp[j][1] + c[i]);
                dp[i][3] = min(dp[i][3], dp[j][2] + c[i]);
            }
        }
    }

    ll ans = LINF;
    for (int i = 1; i <= n; i++) ans = min(ans, dp[i][3]);
    printf("%lld\n", ans == LINF ? -1 : ans);

    return 0;
}
