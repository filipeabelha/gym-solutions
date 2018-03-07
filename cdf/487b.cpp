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

int st[4*N];

void build (int p, int l, int r) {
    if (l == r) { st[p] = INF; return; }
    build(2*p, l, (l+r)/2);
    build(2*p+1, (l+r)/2+1, r);
    st[p] = min(st[2*p], st[2*p+1]);
}

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return INF;
    if (i <= l and r <= j) return st[p];
    int qa = query(2*p, l, (l+r)/2, i, j);
    int qb = query(2*p+1, (l+r)/2+1, r, i, j);
    return min(qa, qb);
}

void upd (int p, int l, int r, int x, int v) {
    if (r < x or x < l) return;
    if (l == r and l == x) { st[p] = min(st[p], v); return; }
    upd(2*p, l, (l+r)/2, x, v);
    upd(2*p+1, (l+r)/2+1, r, x, v);
    st[p] = min(st[2*p], st[2*p+1]);
}

int v[N], f[N];
int n, s, l;

void go (int x) {
    if (f[x]-x+1 < l) return;
    if (f[x] == n) upd(1, 1, n, x, 1);

    int ans = query (1, 1, n, x+l, f[x]+1) + 1;
    ans = min(ans, INF);
    upd(1, 1, n, x, ans);
}

int main () {
    scanf("%d%d%d", &n, &s, &l);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);

    multiset <int> m;
    int j = 0;
    for (int i = 1; i <= n; i++) {
        while (j < n and (m.empty() or *m.rbegin()-*m.begin() <= s)) {
            j++;
            m.insert(v[j]);
        }
        while (j >= 1 and m.size() and *m.rbegin()-*m.begin() > s) {
            m.erase(m.find(v[j]));
            j--;
        }
        f[i] = j;
        m.erase(m.find(v[i]));
    }

    build (1, 1, n);
    for (int i = n; i >= 0; i--) go(i);

    int ans = query (1, 1, n, 1, 1);
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}
