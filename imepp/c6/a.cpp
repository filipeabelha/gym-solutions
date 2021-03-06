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
const int INF = (1 << 30) - 1, MOD = 1e9+7;
const int N = 1e5+5;

int st[4*N], v[N];

void build (int p, int l, int r) {
    if (l == r) {st[p] = v[l]; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = st[2*p] & st[2*p+1];
}

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return INF;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x & y;
}

int tc, n, k;

int main () {
    scanf("%d", &tc);
    while (tc--) {
        cl(st, 0);
        cl(v, 0);

        scanf("%d%d", &n, &k);
        for (int i = n+1;   i <= 2*n; i++) scanf("%d", &v[i]);
        for (int i = 1;     i <= n;   i++) v[i] = v[i+n];
        for (int i = 2*n+1; i <= 3*n; i++) v[i] = v[i-n];
        build(1, 1, 3*n);

        for (int i = n+1; i <= 2*n; i++)
            printf("%d%c", k >= n ? query(1, 1, 3*n, 1, n) : query(1, 1, 3*n, i-k, i+k), " \n"[i==2*n]);

    }

    return 0;
}
