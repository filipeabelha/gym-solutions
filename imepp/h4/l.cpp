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

ll n, m;

ll fexp (ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % MOD;
        b = (b*b) % MOD;
        e >>= 1;
    }
    return ans;
}

ll y (ll x) {
    ll ans = x;
    ans *= fexp(n, m);                ans %= MOD;
    ans *= n-1;                       ans %= MOD;
    ans *= fexp(fexp(n, m)-1, MOD-2); ans %= MOD;
    return ans;
}

int t;

int main () {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &n, &m);
        ll s = fexp(n, m)-1;
        s *= fexp(n-1, MOD-2); s %= MOD;
        printf("%lld %lld\n", s, y(s));
    }
    return 0;
}
