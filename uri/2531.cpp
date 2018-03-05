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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7+5;

int stmax[4*N], stmin[4*N], v[N], n;

void build (int p, int l, int r) {
    if (l == r) {
        stmax[p] = stmin[p] = v[l];
        return;
    }
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    stmax[p] = max(stmax[2*p], stmax[2*p+1]);
    stmin[p] = min(stmin[2*p], stmin[2*p+1]);
}

int querymax (int p, int l, int r, int i, int j) {
    if (r < i or j < l)    return -INF;
    if (i <= l and r <= j) return stmax[p];
    int x = querymax(2*p,   l,   (l+r)/2, i, j);
    int y = querymax(2*p+1, (l+r)/2+1, r, i, j);
    return max(x, y);
}

int querymin (int p, int l, int r, int i, int j) {
    if (r < i or j < l)    return INF;
    if (i <= l and r <= j) return stmin[p];
    int x = querymin(2*p,   l,   (l+r)/2, i, j);
    int y = querymin(2*p+1, (l+r)/2+1, r, i, j);
    return min(x, y);
}

int query (int i, int j) {
    return querymax(1, 1, n, i, j) - querymin(1, 1, n, i, j);
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {
        stmax[p] = stmin[p] = v;
        return;
    }
    update (2*p,   l,   (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);
    stmax[p] = max(stmax[2*p], stmax[2*p+1]);
    stmin[p] = min(stmin[2*p], stmin[2*p+1]);
}

int q, o, a, b;

int main () {
    while (~scanf("%d", &n) and n) {
        for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
        build(1, 1, n);

        scanf("%d", &q);
        while (q--) {
            scanf("%d%d%d", &o, &a, &b);
            if (o == 1) update (1, 1, n, a, b);
            else printf("%d\n", query (a, b));
        }
    }
    return 0;
}
