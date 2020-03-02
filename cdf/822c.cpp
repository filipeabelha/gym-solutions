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
typedef pair<ll, ll> pii;
typedef pair<ll, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll INF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const ll N = 2e5+5;

ll n, c;
map <ll, vector <piii>> m;
set <ll> values;

ll st[4*N], lazy[4*N];

void build (ll p, ll l, ll r) {
    if (l == r) {st[p] = INF; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = min(st[2*p], st[2*p+1]);
}

void push (ll p, ll l, ll r) {
    if (lazy[p]) {
        st[p] = lazy[p];
        if (l != r) {
            lazy[2*p] = lazy[p];
            lazy[2*p+1] = lazy[p];
        }
        lazy[p] = 0;
    }
}

ll query (ll p, ll l, ll r, ll i, ll j) {
    push(p, l, r);
    if (r < i or j < l) return INF;
    if (i <= l and r <= j) return st[p];
    ll x = query(2*p, l, (l+r)/2, i, j);
    ll y = query(2*p+1, (l+r)/2+1, r, i, j);
    return min(x, y);
}

void update (ll p, ll l, ll r, ll i, ll j, ll k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] = k;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    if (l != r) st[p] = min(st[2*p], st[2*p+1]);
}

int main () {
    build(1, 1, N-1);

    ll n, k;
    scanf("%lld%lld", &n, &k);
    for (ll i = 1; i <= n; i++) {
        ll l, r, c;
        scanf("%lld%lld%lld", &l, &r, &c);
        m[r-l+1].pb({l, {r, c}});
        values.insert(r-l+1);
    }
    for (auto& l : values) sort(m[l].begin(), m[l].end());

    ll ans = INF;
    for (auto& l : values) {
        update(1, 1, N-1, 1, N-1, INF);
        for (auto& p : m[l]) {
            ll l = p.st;
            ll r = p.nd.st;
            ll c = p.nd.nd;
            ll v = query(1, 1, N-1, r, r);
            update(1, 1, N-1, r, r, min(v, c));
        }

        for (auto& p : m[k-l]) {
            ll l = p.st;
            ll r = p.nd.st;
            ll c = p.nd.nd;
            ll v = query(1, 1, N-1, 1, l-1);
            ans = min(ans, c+v);
        }
    }

    printf("%lld\n", ans < INF ? ans : -1);

    return 0;
}
