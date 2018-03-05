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
const int N = 1e6+5;

int st[4*N], v[N], lazy[4*N];
int n, x;
vi adj[N], path;
pii ind[N];

void build (int p, int l, int r) {
    if (l == r) { st[p] = v[path[l-1]]; return; }
    build(2*p, l, (l+r)/2);
    build(2*p+1, (l+r)/2+1, r);
    st[p] = st[2*p]+st[2*p+1];
}

void push (int p, int l, int r) {
    if (lazy[p]) {
        st[p] = (r-l+1)-st[p];
        if (l != r) {
            lazy[2*p]   ^= 1;
            lazy[2*p+1] ^= 1;
        }
        lazy[p] = 0;
    }
}

void update (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] ^= 1;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j);
    update(2*p+1, (l+r)/2+1, r, i, j);
    st[p] = st[2*p]+st[2*p+1];
}

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return 0;
    push(p, l, r);
    if (i <= l and r <= j) return st[p];
    return query(2*p, l, (l+r)/2, i, j) +
           query(2*p+1, (l+r)/2+1, r, i, j);
}

void dfs (int u) {
    path.pb(u);
    ind[u].st = path.size();
    for (auto v : adj[u]) dfs(v);
    path.pb(u);
    ind[u].nd = path.size();
}

char w[30];
int q, k;

int main () {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &x);
        adj[x].pb(i);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    dfs(1);
    build(1, 1, 2*n);
    scanf("%d", &q);
    while (q--) {
        scanf(" %s %d", w, &k);
        if (w[0] == 'g') printf("%d\n", query(1, 1, 2*n, ind[k].st, ind[k].nd)/2);
        else update(1, 1, 2*n, ind[k].st, ind[k].nd);
    }
    return 0;
}
