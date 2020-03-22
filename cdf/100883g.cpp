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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll fexp (ll b, ll e, ll m = MOD) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}

ll t, n, m, f[N];

int main () {
    f[0] = f[1] = 1;
    for (ll i = 2; i < N; i++) {
        f[i] = i*f[i-1];
        f[i] %= MOD;
    }

    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &m);
        ll ans = f[n+m]*fexp(f[n], MOD-2);
        ans %= MOD;
        ans *= fexp(f[m], MOD-2);
        ans %= MOD;
        printf("%lld\n", ans);
    }

    return 0;
}
