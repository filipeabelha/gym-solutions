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
const int N = 1e5+5;

ll exp (ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % MOD;
        b = (b*b) % MOD;
        e >>= 1;
    }
    return ans;
}

ll n, m, a[N], b[N], z[N], ans;

int main () {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    for (int i = n; i >= 1; i--) z[i] = z[i+1] + !a[i] + !b[i];

    ll d = 1;
    for (int i = 1; i <= n; i++) {
        ll f = (d*exp(m, z[i+1])) % MOD;
        ll s = 0;

        // loser pos
        if (a[i] and b[i] and a[i] < b[i]) break;

        if (!a[i] and (b[i] == m))         continue;

        if (!a[i] and !b[i])               s = m*(m-1)/2, s %= MOD;
        if (!a[i] and b[i])                s = m-b[i];
        if (a[i] and !b[i])                s = a[i]-1;
        if (a[i] and b[i] and a[i] > b[i]) s = 1;

        ans += s*f; ans %= MOD;

        if (!a[i] and !b[i])               d *= m, d %= MOD;
        if (a[i] and b[i] and a[i] > b[i]) break;

    }
    ans *= exp(exp(m, z[1]), MOD-2);
    ans %= MOD;
    printf("%lld\n", ans);
    return 0;
}
