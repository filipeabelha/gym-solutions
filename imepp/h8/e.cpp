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

int st[4*N][3], lazy[4*N];

void build (int p, int l, int r) {
    if (l == r) {st[p][0] = 1; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p][0] = st[2*p][0] + st[2*p+1][0];
}

void push (int p, int l, int r) {
    if (lazy[p]) {
        int v[3];
        v[(0+lazy[p])%3] = st[p][0];
        v[(1+lazy[p])%3] = st[p][1];
        v[(2+lazy[p])%3] = st[p][2];
        st[p][0] = v[0];
        st[p][1] = v[1];
        st[p][2] = v[2];
        if (l != r) {
            lazy[2*p] += lazy[p];
            lazy[2*p] %= 3;
            lazy[2*p+1] += lazy[p];
            lazy[2*p+1] %= 3;
        }
        lazy[p] = 0;
    }
}

int query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p][0];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

void update (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] += 1;
        lazy[p] %= 3;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j);
    update(2*p+1, (l+r)/2+1, r, i, j);
    if (l != r) {
        st[p][0] = st[2*p][0] + st[2*p+1][0];
        st[p][1] = st[2*p][1] + st[2*p+1][1];
        st[p][2] = st[2*p][2] + st[2*p+1][2];
    }
}

int n, q, a, b, c;

int main () {
    scanf("%d%d", &n, &q);
    build(1, 0, n-1);
    while (q--) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0) update(1, 0, n-1, b, c);
        if (a == 1) printf("%d\n", query(1, 0, n-1, b, c));
    }

    return 0;
}
