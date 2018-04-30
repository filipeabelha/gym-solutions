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

int st[4*N], n, q, l, r, v[N], ac[N][2];

void build (int p, int l, int r) {
    if (l == r) { st[p] = 1; return; }
    int m = (l+r)/2;
    build(2*p, l, m);
    build(2*p+1, m+1, r);
    st[p] = max(st[2*p], st[2*p+1]);
    if (v[m] == v[m+1]) {
        int x = (v[l] != v[m] ? ac[m][0] : ac[m][0] - ac[l][0] + 1);
        int y = (v[r] != v[m+1] ? ac[m+1][1] : ac[m+1][1] - ac[r][1] + 1);
        st[p] = max(st[p], x+y);
    }
}

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l)    return 0;
    if (i <= l and r <= j) return st[p];
    int m = (l+r)/2;
    int qa = query(2*p, l, m, i, j);
    int qb = query(2*p+1, m+1, r, i, j);
    int ans = max(qa, qb);
    if (i <= m and m+1 <= j and v[m] == v[m+1]) {
        int x = (v[i] != v[m] ? ac[m][0] : ac[m][0] - ac[i][0] + 1);
        int y = (v[j] != v[m+1] ? ac[m+1][1] : ac[m+1][1] - ac[j][1] + 1);
        ans = max(ans, x+y);
    }
    return ans;
}

int main () {
    while (~scanf("%d", &n) and n) {
        cl(ac, 0);
        cl(v, 0);
        cl(st, 0);

        scanf("%d", &q);
        for (int i = 1; i <= n; i++) scanf("%d", &v[i]);

        ac[1][0] = ac[n][1] = 1;

        for (int i = 2; i <= n; i++)
            ac[i][0] = (v[i] == v[i-1] ? ac[i-1][0] + 1 : 1);

        for (int i = n-1; i >= 1; i--)
            ac[i][1] = (v[i] == v[i+1] ? ac[i+1][1] + 1 : 1);

        build(1, 1, n);

        while (q--) {
            scanf("%d%d", &l, &r);
            printf("%d\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}
