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
const int N = 1e5+5;

ll st[4*N][2], v[N];

void build (int p, int l, int r) {
    if (l == r) { st[p][0] = st[p][1] = v[l]; return; }
    build(2*p, l, (l+r)/2);
    build(2*p+1, (l+r)/2+1, r);
    st[p][0] = min(st[2*p][0], st[2*p+1][0]);
    st[p][1] = max(st[2*p][1], st[2*p+1][1]);
}

pll query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return {LINF, -LINF};
    if (i <= l and r <= j) return {st[p][0], st[p][1]};
    pll x = query(2*p, l, (l+r)/2, i, j);
    pll y = query(2*p+1, (l+r)/2+1, r, i, j);
    return {min(x.st, y.st), max(x.nd, y.nd)};
}

void update (int p, int l, int r, int x, int v) {
    if (r < x or x < l) return;
    if (l == r and l == x) { st[p][0] = st[p][1] = v; return; }
    update(2*p, l, (l+r)/2, x, v);
    update(2*p+1, (l+r)/2+1, r, x, v);
    if (l != r) {
        st[p][0] = min(st[2*p][0], st[2*p+1][0]);
        st[p][1] = max(st[2*p][1], st[2*p+1][1]);
    }
}

ll n, q, a, b, c;

int main () {
    while (~scanf("%lld", &n)) {
        cl(st, 0);
        cl(v, 0);

        for (int i = 1; i <= n; i++) scanf(" %lld", &v[i]);
        build(1, 1, n);

        scanf(" %lld", &q);
        while (q--) {
            scanf("%lld%lld%lld", &c, &a, &b);
            if (c == 1) update(1, 1, n, a, b);
            if (c == 2) {
                pll p = query(1, 1, n, a, b);
                printf("%lld\n", abs(p.st - p.nd));
            }
        }
    }

    return 0;
}
