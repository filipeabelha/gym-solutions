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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1000000000000000005ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

ll fexp (ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1) {
            if (ans > LLONG_MAX/b) return -1;
            ans = (ans*b);
        }

        if (e == 1) return ans;
        if (b > LLONG_MAX/b) return -1;
        b = (b*b);
        e >>= 1;
    }
    return ans;
}


ll a, b, q;
set <ll> s;
vector <ll> v;

ll query (ll x) {
    ll pos = upper_bound(v.begin(), v.end(), x) - v.begin();
    return pos;
}

ll sqr (ll x) {
    ll l = 0, m, r = INF;
    while (l < r) {
        m = (l+r+1)/2;
        if (m*m > x) r = m-1;
        else l = m;
    }
    return l;
}

int main () {
    for (ll b = 2; b <= N; b++) {
        for (ll e = 3; ; e++) {
            ll k = fexp(b, e);
            if (k == -1) break;
            ll z = sqr(k);
            if (z*z != k) s.insert(k);
        }
    }
    for (auto x : s) v.pb(x);
    scanf("%lld", &q);
    while (q--) {
        scanf("%lld%lld", &a, &b); a--;
        ll ans = query(b) - query(a);
        printf("%lld\n", ans + sqr(b) - sqr(a));
    }
    return 0;
}
