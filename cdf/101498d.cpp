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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll fact[N], inv[N], ans;

ll exp (ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = ans*b % MOD;
        b = b*b % MOD;
        e /= 2;
    }
    return ans;
}

ll n, a, b;

int main () {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = (fact[i-1]*i) % MOD;
    for (int i = 0; i < N; i++) inv[i] = exp(fact[i], MOD-2);
    scanf("%lld", &n);
    while (n--) {
        scanf("%lld%lld", &a, &b);

        ans = 2*fact[a-1]; ans %= MOD;
        ans *= inv[b];     ans %= MOD;
        ans *= inv[a-b-1]; ans %= MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
