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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e6+5;

ll fexp (ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % MOD;
        b = (b*b) % MOD;
        e >>= 1;
    }
    return ans;
}

int cmp[N];
vector <ll> p;

void primes () {
    for (ll i = 2; i*i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
    }
    for (ll i = 2; i < N; i++) if (!cmp[i]) p.pb(i);
}


int q;
ll x, y, ans;
ll f[N], inv[N];

int main () {
    primes();
    f[0] = f[1] = 1;
    for (int i = 2; i < N; i++) f[i] = (i*f[i-1]) % MOD;
    for (int i = 0; i < N; i++) inv[i] = fexp(f[i], MOD-2);

    scanf("%d", &q);
    while (q--) {
        ans = 1;
        scanf("%lld%lld", &x, &y);
        for (int i = 0; p[i]*p[i] <= x; i++) {
            int e = 0;
            while (x % p[i] == 0) {
                e++;
                x /= p[i];
            }
            ans *= f[y-1+e]; ans %= MOD;
            ans *= inv[y-1]; ans %= MOD;
            ans *= inv[e];   ans %= MOD;
        }
        if (x > 1) ans *= y, ans %= MOD;
        ans *= fexp(2, y-1); ans %= MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
