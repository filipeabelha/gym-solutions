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
const int N = 1e6+10;

int cmp[N];
vi pr;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
        pr.pb(i);
    }
}

ll phi (ll n) {
    ll ind = 0, ans = n;
    ll pf = pr[0];
    while (pf * pf <= n) {
        if (n % pf == 0) ans -= ans/pf;
        while (n % pf == 0) n /= pf;
        pf = pr[++ind];
    }
    if (n != 1) ans -= ans/n;
    return ans;
}

ll fexp (ll b, ll e, ll m = MOD) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}

ll solve (ll n, ll m) {
    ll p = phi(m);
    if (n == 1 or p == 1) return n%m;
    if (n <= 5) return fexp(n, solve(n-1, MOD), m);

    ll e = p + solve(n-1, p);
    return fexp(n, e, m);
}

int main () {
    ll n, m;
    scanf("%lld%lld", &n, &m);

    primes();

    printf("%lld\n", solve(n, m));


    return 0;
}
