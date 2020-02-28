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
const int N = 2e5+5;

ll n, m, k, s;
vector <ll> a, b, t, c;
vector <pll> mna, mnb;
vector <pair <ll, pll> > prices;

bool ok (ll x, int pr = 0) {
    prices.clear();
    for (int i = 0; i < m; i++) {
        if (t[i] == 1) prices.pb({c[i]*mna[x].st, {i+1, mna[x].nd}});
        if (t[i] == 2) prices.pb({c[i]*mnb[x].st, {i+1, mnb[x].nd}});
    }
    sort(prices.begin(), prices.end());
    ll sum = 0;
    for (int i = 0; i < k; i++) {
        sum += prices[i].st;
        if (pr) {
            printf("%lld %lld\n", prices[i].nd.st, prices[i].nd.nd);
        }
    }
    return (sum <= s);
}

int main () {
    scanf("%lld%lld%lld%lld", &n, &m, &k, &s);
    a.resize(n);
    b.resize(n);
    mna.resize(n);
    mnb.resize(n);
    t.resize(m);
    c.resize(m);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i > 0) {
            mna[i] = mna[i-1];
            if (mna[i].st > a[i]) mna[i] = {a[i], i+1};
        } else mna[i] = {a[i], i+1};
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        if (i > 0) {
            mnb[i] = mnb[i-1];
            if (mnb[i].st > b[i]) mnb[i] = {b[i], i+1};
        } else mnb[i] = {b[i], i+1};
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &t[i], &c[i]);
    }

    ll l = 0, mid, r = n-1;
    while (l < r) {
        mid = (l+r)/2;
        if (!ok(mid)) l = mid+1;
        else r = mid;
    }

    if (ok(l)) {
        printf("%lld\n", l+1);
        ok(l, 1);

    } else printf("-1\n");

    return 0;
}
