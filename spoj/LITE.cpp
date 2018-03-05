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

int st[4*N], v[N], lazy[4*N];

void push (int p, int l, int r) {
    if (lazy[p]) {
        st[p] = (r-l+1)-st[p];
        if (l != r) {
            lazy[2*p] ^= 1;
            lazy[2*p+1] ^= 1;
        }
        lazy[p] = 0;
    }
}

void update (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] = 1;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j);
    update(2*p+1, (l+r)/2+1, r, i, j);
    if (l != r) st[p] = st[2*p]+st[2*p+1];
}

int query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

int n, m, o, a, b;

int main () {
    while (~scanf("%d%d", &n, &m)) while (m--) {
        scanf("%d%d%d", &o, &a, &b);
        if (o) printf("%d\n", query(1, 1, n, a, b));
        else update(1, 1, n, a, b);
    }
    return 0;
}
