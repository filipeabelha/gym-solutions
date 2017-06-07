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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e5+10;

int cmp[N];
vi pr;

ll phi(ll n) {
    ll ind=0, ans=n;
    ll pf=pr[0];
    while (pf * pf <= n) {
        if (n%pf==0) ans-=ans/pf;
        while (n%pf==0) n/=pf;
        pf = pr[++ind];
    }
    if (n!=1) ans-=ans/n;
    return ans;
}

ll exp(ll b, ll e, ll mod) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = ans*b % mod;
        b = b*b % mod;
        e /= 2;
    }
    return ans;
}

void primes() {
    for (ll i = 2; i <= N; ++i) if (!cmp[i]) {
        for (ll j = i*i; j <= N; j+=i) cmp[j] = 1;
        pr.pb(i);
    }
}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

void extgcd(ll a, ll b, ll &x, ll &y, ll &d) {
    if (b) extgcd(b, a%b, y, x, d), y -= x*(a/b);
    else x = 1, y = 0, d = a;
}

ll n, e, c, f, p, d, k, g;

int main () {
    // Solution #1

    /*
    scanf("%lld%lld%lld", &n, &e, &c);
    primes();
    p = phi(n);
    f = phi(p);
    d = exp(e, f-1, p);
    printf("%lld\n", exp(c, d, n));
    */

    // Solution #2

    scanf("%lld%lld%lld", &n, &e, &c);
    primes();
    p = phi(n);
    extgcd(e, p, d, k, g);
    d = (d%p + p) % p;
    printf("%lld\n", exp(c, d, n));

    return 0;
}
