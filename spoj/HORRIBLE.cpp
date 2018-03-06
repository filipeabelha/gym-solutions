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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll st[4*N], lazy[4*N];

void push (int p, int l, int r) {
    if (lazy[p]) {
        st[p] += (r-l+1)*lazy[p];
        if (l != r) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
}

ll query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return 0;
    push(p, l, r);
    if (i <= l and r <= j) return st[p];
    return query(2*p, l, (l+r)/2, i, j) +
           query(2*p+1, (l+r)/2+1, r, i, j);
}

void update (int p, int l, int r, int i, int j, int k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] += k;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    st[p] = st[2*p] + st[2*p+1];
}

int t, n, c, o, a, b, k;

int main () {
    scanf("%d", &t);
    while (t--) {
        cl(st, 0);
        cl(lazy, 0);
        scanf("%d%d", &n, &c);
        while (c--) {
            scanf("%d%d%d", &o, &a, &b);
            if (o == 1) printf("%lld\n", query(1, 1, n, a, b));
            else {
                scanf("%d", &k);
                update(1, 1, n, a, b, k);
            }
        }
    }
    return 0;
}
