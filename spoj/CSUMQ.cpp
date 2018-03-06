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

ll st[4*N], v[N];

void build (int p, int l, int r) {
    if (l == r) { st[p] = v[l]; return; }
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = st[2*p]+st[2*p+1];
}

ll query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    return query(2*p, l, (l+r)/2, i, j) +
           query(2*p+1, (l+r)/2+1, r, i, j);
}

int n, q, a, b;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);

    build(1, 1, n);

    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &a, &b);
        printf("%lld\n", query(1, 1, n, ++a, ++b));
    }
    return 0;
}
