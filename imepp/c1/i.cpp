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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 5e3+5;

ll x, y, z, ans = 1, f[N];

ll exp (ll b, ll e) {
    ll r = 1;
    while (e) {
        if (e&1) r = (r*b) % MOD;
        b = (b*b) % MOD;
        e >>= 1;
    }
    return r;
}

ll eval (ll a, ll b) {
    ll z = 0;
    for (int i = 1; i <= min(a, b); i++) {
        ll r = 1;
        r *= exp(f[a], MOD);     r %= MOD;
        r *= exp(f[b], MOD);     r %= MOD;
        r *= exp(f[i], MOD-2);   r %= MOD;
        r *= exp(f[a-i], MOD-2); r %= MOD;
        r *= exp(f[b-i], MOD-2); r %= MOD;
        z += r;
        z %= MOD;
    }
    return (z+1)%MOD;
}

int main () {
    f[1] = f[0] = 1;
    for (int i = 2; i < N; i++) f[i] = (f[i-1]*i)%MOD;
    scanf("%lld%lld%lld", &x, &y, &z);
    ans *= eval(x, y); ans %= MOD;
    ans *= eval(y, z); ans %= MOD;
    ans *= eval(x, z); ans %= MOD;
    printf("%lld\n", ans);
    return 0;
}
