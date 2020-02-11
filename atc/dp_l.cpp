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
const int N = 3e3+5;

ll n, v[N], memo[N][N][2];

ll dp (ll l, ll r, ll c) {
    if (memo[l][r][c] != LINF) return memo[l][r][c];

    if (c == 0) {
        if (l == r) return memo[l][r][c] = v[l];
        return memo[l][r][c] = max(v[l] + dp(l+1, r, c^1),
                                   v[r] + dp(l, r-1, c^1));
    }

    if (c == 1) {
        if (l == r) return memo[l][r][c] = -v[l];
        return memo[l][r][c] = min(-v[l] + dp(l+1, r, c^1),
                                   -v[r] + dp(l, r-1, c^1));
    }
}


int main () {
    cl(memo, 63);

    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);

    printf("%lld\n", dp(1, n, 0));


    return 0;
}
