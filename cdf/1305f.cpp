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
const int N = 1e6+5;

ll n, ans = LINF, v[N], cmp[N];
vl pr;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
        pr.pb(i);
    }
}

set <ll> fact;

void factorize (ll n) {
    for(int i = 0; pr[i]*pr[i] <= n; i++)
        while (n % pr[i] == 0) fact.insert(pr[i]), n /= pr[i];
    if (n > 1) fact.insert(n);
}

void solve (ll d) {
    ll cur = 0;
    for (ll i = 1; i <= n; i++) {
        ll nxt = d*((v[i]-1)/d + 1);
        ll pas = d*((v[i]-1)/d);
        if (pas == 0) cur += nxt-v[i];
        else cur += min(nxt-v[i], v[i]-pas);
    }
    ans = min(ans, cur);
}

int main () {
    primes();

    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);

    random_shuffle(v+1, v+1+n);

    solve(2);

    for (int k = 1; k <= min(n, 100ll); k++) {
        for (int z = -1; z <= 1; z++) {
            ll d = v[k]+z;
            if (d < 2) continue;
            factorize(d);
        }
    }
    for (auto d : fact) solve(d);
    printf("%lld\n", ans);

    return 0;
}
