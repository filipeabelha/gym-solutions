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

ll fexp (ll b, ll e, ll mod) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % mod;
        b = (b*b) % mod;
        e >>= 1;
    }
    return ans;
}


ll x, k, ans;

int main () {
    scanf("%lld%lld", &x, &k);

    if (x == 0) return printf("0\n"), 0;

    x %= MOD;

    ll u = fexp(2ll, k, MOD); u %= MOD;
    u += MOD;                 u %= MOD;

    ll v = x*2ll - 1ll;       v %= MOD;
    v += MOD;                 v %= MOD;

    ans = u*v + 1ll;          ans %= MOD;
    ans += MOD;               ans %= MOD;

    printf("%lld\n", ans);

    return 0;
}
