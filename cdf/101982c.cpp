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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 1e3+5;

ll n, k, x, cnt, f[N], dp[N][N];
map <ll, ll> id;

int main () {
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        if (!id[x]) id[x] = ++cnt;
        f[id[x]]++;
    }

    dp[0][0] = 1;
    for (int i = 1; i <= cnt; i++) {
        dp[i][0] = 1;
        for (int k = 1; k < N; k++) {
            dp[i][k] = dp[i-1][k] + dp[i-1][k-1] * f[i];
            dp[i][k] %= MOD;
        }
    }

    printf("%lld\n", dp[cnt][k]);


    return 0;
}
