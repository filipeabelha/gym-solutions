#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e3+5;

int n, vis[2*N], ord[2*N], ordn, cnt, cmp[2*N], val[N];
vector <int> adj[2*N], adjt[2*N];

int v (int x) { return 2*x; }
int nv (int x) { return 2*x+1; }

void add (int p, int q, int eq = 0) {
    adj[p].push_back(q);
    adjt[q].push_back(p);
    if (!eq) {
        adj[q^1].push_back(p^1);
        adjt[p^1].push_back(q^1);
    }
}

void dfs (int x) {
    vis[x] = 1;
    for (auto v : adj[x]) if (!vis[v]) dfs(v);
    ord[ordn++] = x;
}

void dfst (int x) {
    cmp[x] = cnt, vis[x] = 0;
    for (auto v : adjt[x]) if (vis[v]) dfst(v);
}

vector <pii> e;

void init (int i = 0) {
    ordn = cnt = 0;
    cl(vis, 0);
    cl(ord, 0);
    cl(cmp, 0);
    cl(val, 0);
    for (int k = 0; k < 2*N; k++) {
        adj[k].clear();
        adjt[k].clear();
    }

    if (i > 0) {
        add(nv(i), v(i), 1);
    }

    for (auto p : e) {
        int x = p.st;
        int y = p.nd;

        int X  = x > 0 ?  v(abs(x)) : nv(abs(x));
        int NX = x > 0 ? nv(abs(x)) :  v(abs(x));

        int Y  = y > 0 ?  v(abs(y)) : nv(abs(y));
        int NY = y > 0 ? nv(abs(y)) :  v(abs(y));

        add(NX, Y);
        add(NY, X);
    }
}

bool run2sat() {
    for (int i = 1; i <= n; i++) {
        if (!vis[v(i)]) dfs(v(i));
        if (!vis[nv(i)]) dfs(nv(i));
    }
    for (int i = ordn-1; i >= 0; i--)
        if (vis[ord[i]]) cnt++, dfst(ord[i]);
    for (int i = 1; i <= n; i++) {
        if (cmp[v(i)] == cmp[nv(i)]) return false;
        val[i] = cmp[v(i)] > cmp[nv(i)];
    }
    return true;
}

int m, ok;

int main () {
    scanf("%d%d", &n, &m);
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        e.pb({x, y});

        if (x < 0 and y < 0) ok = 1;
    }

    init();

    if (!run2sat()) {
        printf("0\n");
        return 0;
    }

    if (!ok) {
        printf("-1\n");
        return 0;
    }

    int imp = 0;
    for (int i = 1; i <= n; i++) {
        init(i);
        if (!run2sat()) imp = 1;
    }

    printf("%d\n", imp ? 1 : 2);

    return 0;
}
