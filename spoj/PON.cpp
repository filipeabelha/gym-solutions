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

typedef unsigned long long ll;
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
const int N = 1e5+5;

ll mulmod (ll a, ll b, ll m = MOD) {
    ll r = 0;
    for (a %= m; b; b >>= 1, a = (a*2)%m) if (b&1) r = (r+a)%m;
    return r;
}

ll fexp (ll b, ll e, ll mod) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = mulmod(ans, b, mod);
        b = mulmod(b, b, mod);
        e >>= 1;
    }
    return ans;
}

bool miller (ll a, ll n) {
    if (a >= n) return 1;
    ll s = 0, d = n-1;
    while (d%2 == 0 and d) d >>= 1, s++;
    ll x = fexp(a, d, n);
    if (x == 1 or x == n-1) return 1;
    for (int r = 0; r < s; r++, x = mulmod(x,x,n)) {
        if (x == 1) return 0;
        if (x == n-1) return 1;
    }
    return 0;
}

bool isprime (ll n) {
    int base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (int i = 0; i < 12; i++) if (!miller(base[i], n)) return 0;
    for (int i = 0; i < 50; i++) if (!miller(llrand(), n)) return 0;
    return 1;
}

int t;
ll x;

int main () {
    scanf("%d", &t);
    while (t--) {
        scanf("%llu", &x);
        printf("%s\n", isprime(x) ? "YES" : "NO");
    }
    return 0;
}
