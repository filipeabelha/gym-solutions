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
const int N = 1e5+5;

ll st[4*N][25], v[N], lazy[4*N][25];
int n, q, a, b, c, d;

void build (int t, int p, int l, int r) {
    if (l == r) {
        st[p][t] = ((v[l]&(1 << t)) > 0);
        return;
    }
    build (t, 2*p, l, (l+r)/2);
    build (t, 2*p+1, (l+r)/2+1, r);
    st[p][t] = st[2*p][t]+st[2*p+1][t];
}

void push (int t, int p, int l, int r) {
    if (lazy[p][t]) {
        st[p][t] = (r-l+1)-st[p][t];
        if (l != r) {
            lazy[2*p][t] ^= 1;
            lazy[2*p+1][t] ^= 1;
        }
        lazy[p][t] = 0;
    }
}

ll query (int t, int p, int l, int r, int i, int j) {
    push(t, p, l, r);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p][t];
    ll x = query(t, 2*p, l, (l+r)/2, i, j);
    ll y = query(t, 2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

void update (int t, int p, int l, int r, int i, int j) {
    push(t, p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p][t] = 1;
        push(t, p, l, r);
        return;
    }
    update(t, 2*p, l, (l+r)/2, i, j);
    update(t, 2*p+1, (l+r)/2+1, r, i, j);
    if (l != r) st[p][t] = st[2*p][t] + st[2*p+1][t];
}

ll qry (int l, int r) {
    ll ans = 0;
    for (int i = 0; i < 21; i++)
        ans += query(i, 1, 1, n, l, r)*(1 << i);
    return ans;
}

void upd (int l, int r, int x) {
    for (int i = 0; i < 21; i++) if (x&(1 << i)) {
        update(i, 1, 1, n, l, r);
    }
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
    for (int i = 0; i < 21; i++) build(i, 1, 1, n);

    scanf("%d", &q);

    while (q--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d", &b, &c);
            printf("%lld\n", qry(b, c));
        } else {
            scanf("%d%d%d", &b, &c, &d);
            upd(b, c, d);
        }
    }
    return 0;
}
