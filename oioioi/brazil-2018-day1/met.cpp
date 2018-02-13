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
typedef vector<ll> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e5+5;

ll n, m, k, pt, o[N], p[N], l[N], r[N], a[N], ans[N], bit[N];
vi cities[N];

void add (ll p, ll v) {
    for (p+=1; p<N; p += p&-p) bit[p] += v;
}

ll qry (ll p) {
    ll r = 0;
    for (p+=1; p; p -= p&-p) r += bit[p];
    return r;
}

void go (ll u, ll v, vi st) {
    ll mid = (u+v)/2;

    if (mid > pt) {
        for (ll q = pt+1; q <= mid; q++) {
            if (l[q] <= r[q]) add(l[q], a[q]),  add(r[q]+1, -a[q]);
            else              add(1, a[q]),     add(r[q]+1, -a[q]), add(l[q], a[q]);
        }
    } else {
        for (ll q = pt; q > mid; q--) {
            if (l[q] <= r[q]) add(l[q], -a[q]), add(r[q]+1, a[q]);
            else              add(1, -a[q]),    add(r[q]+1, a[q]),  add(l[q], -a[q]);
        }
    }

    pt = mid;

    if (u == v) {
        for (auto s : st) {
            ll sum = 0;
            for (auto c : cities[s]) sum = min(sum + qry(c), p[s]);
            if (sum == p[s]) ans[s] = u;
        }
        return;
    }

    vi lef;
    vi rig;

    for (auto s : st) {
        ll sum = 0;
        for (auto c : cities[s]) sum = min(sum + qry(c), p[s]);
        if (sum == p[s]) lef.pb(s);
        else rig.pb(s);
    }

    go(u,     mid, lef);
    go(mid+1, v,   rig);
}

int main () {
    cl(ans, -1);

    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%lld", &o[i]), cities[o[i]].pb(i);
    for (int i = 1; i <= n; i++) scanf("%lld", &p[i]);
    scanf("%lld", &k);
    for (int i = 1; i <= k; i++) scanf("%lld%lld%lld", &l[i], &r[i], &a[i]);

    vi v;
    for (int i = 0; i <= n; i++) v.pb(i);
    go(0, k, v);

    for (int i = 1; i <= n; i++) {
        if (ans[i] >= 0) printf("%lld\n", ans[i]);
        else printf("NIE\n");
    }

    return 0;
}
