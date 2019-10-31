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
const int N = 1e6+5;

string s;
ll n, dp[N][6];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = s.size();

    if (s[0] == '0' or s[0] == '?') dp[0][1]++;
    if (s[0] == '1' or s[0] == '?') dp[0][3]++;
    if (s[0] == '*' or s[0] == '?') dp[0][5]++;

    for (int i = 1; i < n; i++) {
        if (s[i] == '0' or s[i] == '?') {
            dp[i][1] += dp[i-1][1];
            dp[i][1] += dp[i-1][2];
        }
        if (s[i] == '1' or s[i] == '?') {
            dp[i][2] += dp[i-1][5];
            dp[i][3] += dp[i-1][1];
            dp[i][3] += dp[i-1][2];
        }
        if (s[i] == '2' or s[i] == '?') {
            dp[i][4] += dp[i-1][5];
        }
        if (s[i] == '*' or s[i] == '?') {
            dp[i][5] += dp[i-1][3];
            dp[i][5] += dp[i-1][4];
            dp[i][5] += dp[i-1][5];
        }
        for (int k = 1; k <= 5; k++) dp[i][k] %= MOD;
    }

    ll ans = 0;
    ans += dp[n-1][1];
    ans += dp[n-1][2];
    ans += dp[n-1][5];
    ans %= MOD;
    printf("%lld\n", ans);

    return 0;
}
