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
const int N = 11e5+5;

int st[4*N], lz[4*N][2], tc, q, cnt, qcnt, p, k, l, r, n, sz;
bitset <N> s;
string t;
char c;

void build (int p, int l, int r) {
    if (l == r) { st[p] = s[l]; return; }
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = st[2*p] + st[2*p+1];
}

// 0 = flip
// 1 = set

void push (int p, int l, int r) {
    if (lz[p][0] == 1) {
        st[p] = r-l+1 - st[p];

        if      (lz[2*p][1] >=  0)   lz[2*p][1] ^= 1;
        else if (lz[2*p][0] ==  1)   lz[2*p][0] = -1;
        else if (lz[2*p][0] == -1)   lz[2*p][0] = 1;

        if      (lz[2*p+1][1] >=  0) lz[2*p+1][1] ^= 1;
        else if (lz[2*p+1][0] ==  1) lz[2*p+1][0] = -1;
        else if (lz[2*p+1][0] == -1) lz[2*p+1][0] = 1;

        lz[p][0] = -1;
    }
    if (lz[p][1] >= 0) {
        st[p] = (r-l+1)*lz[p][1];

        lz[2*p][0] = lz[2*p+1][0] = -1;
        lz[2*p][1] = lz[2*p+1][1] = lz[p][1];

        lz[p][1] = -1;
    }
}

void update (int p, int l, int r, int i, int j, int v) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        if (v == 2) {
            if      (lz[p][1] >=  0) lz[p][1] ^= 1;
            else if (lz[p][0] ==  1) lz[p][0] = -1;
            else if (lz[p][0] == -1) lz[p][0] = 1;
            push(p, l, r);
            return;
        }
        lz[p][0] = -1;
        lz[p][1] = v;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, v);
    update(2*p+1, (l+r)/2+1, r, i, j, v);
    st[p] = st[2*p] + st[2*p+1];
}

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return 0;
    push(p, l, r);
    if (i <= l and r <= j) return st[p];
    int a = query(2*p, l, (l+r)/2, i, j);
    int b = query(2*p+1, (l+r)/2+1, r, i, j);
    return a+b;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> tc;
    while (tc-- and ++cnt) {
        printf("Case %d:\n", cnt);
        s = 0;
        sz = 0;
        qcnt = 0;
        cl(lz, -1);

        cin >> p;
        while (p--) {
            cin >> k >> t;
            while (k--) for (auto c : t) s[sz++] = c-'0';
        }
        n = sz;
        build(1, 0, n-1);

        cin >> q;
        while (q--) {
            cin >> c >> l >> r;
            if (c == 'S') printf("Q%d: %d\n", ++qcnt, query(1, 0, n-1, l, r));
            if (c == 'E') update(1, 0, n-1, l, r, 0);
            if (c == 'F') update(1, 0, n-1, l, r, 1);
            if (c == 'I') update(1, 0, n-1, l, r, 2);
        }
    }
    return 0;
}
