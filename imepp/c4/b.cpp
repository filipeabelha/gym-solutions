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

ll fexp (ll b, ll e, ll m) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}

bool miller(ll a, ll n) {
    if (a >= n) return 1;
    ll s = 0, d = n-1;
    while (d%2 == 0 and d) d >>= 1, s++;
    ll x = fexp(a, d, n);
    if (x == 1 or x == n-1) return 1;
    for (int r = 0; r < s; r++, x = fexp(x, 2, n)) {
        if (x == 1) return 0;
        if (x == n-1) return 1;
    }
    return 0;
}

bool isprime(ll n) {
    int base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (int i = 0; i < 12; ++i) if (!miller(base[i], n)) return 0;
    return 1;
}

ll n, l, r;

int main () {
    scanf("%lld", &n);
    while (n--) {
        scanf("%lld%lld", &l, &r);
        for (ll i = l; i <= r; i++) if (i != 1 and isprime(i)) printf("%lld\n", i);
        if (n) printf("\n");
    }

    return 0;
}
