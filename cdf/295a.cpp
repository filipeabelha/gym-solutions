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

ll st[4*N][2], lazy[4*N][2], op[N][3], v[N];
ll n, m, k, a, b;

void build (int p, int l, int r) {
    if (l == r) { st[p][1] = v[l]; return; }
    build(2*p, l, (l+r)/2);
    build(2*p+1, (l+r)/2+1, r);
    st[p][1] = st[2*p][1] + st[2*p+1][1];
}

void push (int z, int p, int l, int r) {
    if (lazy[p][z]) {
        st[p][z] += (r-l+1)*lazy[p][z];
        if (l != r) {
            lazy[2*p][z] += lazy[p][z];
            lazy[2*p+1][z] += lazy[p][z];
        }
        lazy[p][z] = 0;
    }
}

void update (int z, int p, int l, int r, int i, int j, ll v) {
    push(z, p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p][z] += v;
        push(z, p, l, r);
        return;
    }
    update(z, 2*p, l, (l+r)/2, i, j, v);
    update(z, 2*p+1, (l+r)/2+1, r, i, j, v);
    st[p][z] = st[2*p][z] + st[2*p+1][z];
}

ll query (int z, int p, int l, int r, int i, int j) {
    if (r < i or j < l) return 0;
    push(z, p, l, r);
    if (i <= l and r <= j) return st[p][z];
    return query(z, 2*p, l, (l+r)/2, i, j) +
           query(z, 2*p+1, (l+r)/2+1, r, i, j);
}

int main () {
    scanf("%lld%lld%lld", &n, &m, &k);

    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);

    for (int i = 1; i <= m; i++)
        scanf("%lld%lld%lld", &op[i][0], &op[i][1], &op[i][2]);

    for (int i = 1; i <= k; i++) {
        scanf("%lld%lld", &a, &b);
        update(0, 1, 1, m, a, b, 1);
    }

    build(1, 1, n);

    for (int i = 1; i <= m; i++) {
        int w = query(0, 1, 1, m, i, i);
        update(1, 1, 1, n, op[i][0], op[i][1], op[i][2]*w);
    }

    for (int i = 1; i <= n; i++)
        printf("%lld%c", query(1, 1, 1, n, i, i), " \n"[i==n]);
    return 0;
}
