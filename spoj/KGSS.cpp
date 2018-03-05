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

pii st[4*N];
int v[N], lazy[4*N];

void build (int p, int l, int r) {
    if (l == r) {
        st[p] = {v[l], -1};
        return;
    }
    build(2*p, l, (l+r)/2);
    build(2*p+1, (l+r)/2+1, r);

    int z[] = {-st[2*p].st, -st[2*p].nd, -st[2*p+1].st, -st[2*p+1].nd};
    sort(z, z+4);
    st[p] = {-z[0], -z[1]};
}

int n, q, a, b;
char c;

pii query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return {-1, -1};
    if (i <= l and r <= j) return st[p];

    pii a = query(2*p, l, (l+r)/2, i, j);
    pii b = query(2*p+1, (l+r)/2+1, r, i, j);

    int z[] = {-a.st, -a.nd, -b.st, -b.nd};
    sort(z, z+4);
    return {-z[0], -z[1]};
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) { st[p] = {v, -1}; return; }

    update(2*p, l, (l+r)/2, x, v);
    update(2*p+1, (l+r)/2+1, r, x, v);

    int z[] = {-st[2*p].st, -st[2*p].nd, -st[2*p+1].st, -st[2*p+1].nd};
    sort(z, z+4);
    st[p] = {-z[0], -z[1]};
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);

    build(1, 1, n);

    scanf("%d", &q);
    while (q--) {
        scanf(" %c %d %d", &c, &a, &b);
        if (c == 'Q') {
            pii p = query(1, 1, n, a, b);
            printf("%d\n", p.st+p.nd);
        } else update (1, 1, n, a, b);
    }
    return 0;
}
