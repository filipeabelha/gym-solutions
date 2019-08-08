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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 4e5+10;

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
vi pr;

void primes() {
    for (ll i = 2; i < 910; i++) if (!cmp[i]) {
        for (ll j = i*i; j < 910; j+=i) cmp[j] = 1;
        pr.pb(i);
    }
}

ll v[N], mask[N], inv[N];
pll st[4*N], lazy[4*N];

void build (int p, int l, int r) {
    if (l == r) {
        st[p].nd = v[l];
        st[p].st |= mask[v[l]];
        return;
    }
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p].st =  st[2*p].st | st[2*p+1].st;
    st[p].nd = (st[2*p].nd * st[2*p+1].nd) % MOD;
}

void push (int p, int l, int r) {
    if (lazy[p].st) {
        if (l != r) {
            lazy[2*p].st   |= lazy[p].st;
            lazy[2*p+1].st |= lazy[p].st;

            lazy[2*p].nd   *= lazy[p].nd;  lazy[2*p].nd   %= MOD;
            lazy[2*p+1].nd *= lazy[p].nd;  lazy[2*p+1].nd %= MOD;
        }
        st[p].st |= lazy[p].st;

        st[p].nd *= fexp(lazy[p].nd, r-l+1);
        st[p].nd %= MOD;


        lazy[p] = {0, 1};
    }
}

pll query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return {0, 1};
    if (i <= l and r <= j) return st[p];
    pll x = query(2*p, l, (l+r)/2, i, j);
    pll y = query(2*p+1, (l+r)/2+1, r, i, j);
    return {(x.st | y.st), (x.nd * y.nd) % MOD};
}

void update (int p, int l, int r, int i, int j, int k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p].nd *= k;
        lazy[p].nd %= MOD;
        lazy[p].st |= mask[k];
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    if (l != r) {
        st[p].st =  st[2*p].st | st[2*p+1].st;
        st[p].nd = (st[2*p].nd * st[2*p+1].nd) % MOD;
    }
}

string s;
ll n, q, x, y, z;

int main () {
    for (int i = 0; i < 4*N; i++) lazy[i] = st[i] = {0, 1};
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primes();
    for (int i = 2; i < N; i++) {
        int x = i;
        for (int j = 0; j < 63; j++) {
            while (x % pr[j] == 0) {
                x /= pr[j];
                mask[i] |= (1ll << j);
            }
        }
    }
    for (int i = 0; i < 63; i++) inv[i] = fexp(pr[i], MOD-2);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> v[i];
    build(1, 1, n);

    while (q--) {
        cin >> s >> x >> y;
        if (s[0] == 'M') {
            cin >> z;
            update(1, 1, n, x, y, z);
        } else {
            pll k = query(1, 1, n, x, y);
            ll ans = k.nd;
            for (int i = 0; i < 63; i++) if (k.st & (1ll << i)) {
                ans *= pr[i]-1;  ans %= MOD;
                ans *= inv[i];   ans %= MOD;
            }
            cout << ans << endl;
        }
    }

    return 0;
}
