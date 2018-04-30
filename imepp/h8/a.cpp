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

ll st[4*N], v[N];

void build (int p, int l, int r) {
    if (l == r) { st[p] = v[l]; return; }
    build(2*p, l, (l+r)/2);
    build(2*p+1, (l+r)/2+1, r);
    st[p] = max(st[2*p], st[2*p+1]);
}

ll query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return -LINF;
    if (i <= l and r <= j) return st[p];
    ll x = query(2*p, l, (l+r)/2, i, j);
    ll y = query(2*p+1, (l+r)/2+1, r, i, j);
    return max(x, y);
}

void update (int p, int l, int r, int x, int v) {
    if (r < x or x < l) return;
    if (l == r and l == x) { st[p] = v; return; }
    update(2*p, l, (l+r)/2, x, v);
    update(2*p+1, (l+r)/2+1, r, x, v);
    if (l != r) st[p] = max(st[2*p], st[2*p+1]);
}

ll tc, n, q, a, b, x;
char c;

int main () {
    scanf("%lld", &tc);
    for (int t = 0; t < tc; t++) {
        cl(st, 0);
        cl(v, 0);
        printf("Testcase %d:\n", t);

        scanf(" %lld %lld", &n, &x);

        for (int i = 0; i < n; i++) scanf(" %lld", &v[i]);
        build(1, 0, n-1);

        scanf(" %lld", &q);
        while (q--) {
            scanf(" %c", &c);
            if (c == 'A') {
                scanf(" %lld", &a);
                x += a;
            }
            if (c == 'B') {
                scanf(" %lld %lld", &a, &b);
                update(1, 0, n-1, a, b);
            }
            if (c == 'C') {
                scanf(" %lld %lld", &a, &b);
                ll z = query(1, 0, n-1, a, b);
                printf("%lld\n", abs(x-z));
            }
        }
        printf("\n");
    }

    return 0;
}
