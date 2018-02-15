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

int n, a, b, vis[N], sz[N], f[N];
vi adj[N], cent, lea[N];

void dfs (int u) {
    bool ok = true;
    sz[u] = 1;

    for (auto v : adj[u]) if (!vis[v]) {
        vis[v] = 1;
        dfs(v);
        sz[u] += sz[v];
        if (2*sz[v] > n) ok = false;
    }

    if (ok and 2*(n-sz[u]) <= n) cent.pb(u);
}

void cnt (int u, int s) {
    if (adj[u].size() == 1) {
        f[s]++;
        lea[s].pb(u);
    }

    for (auto v : adj[u]) if (!vis[v]) {
        vis[v] = 1;
        cnt(v, s);
    }
}

priority_queue <pii> pq;
vector <pii> ans;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n-1; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        vis[i] = 1;
        dfs(i);
    }

    cl(vis, 0);
    int c = cent[0];
    vis[c] = 1;
    for (auto v : adj[c]) {
        vis[v] = 1;
        cnt(v, v);
        pq.push(mp(f[v], v));
    }

    while (pq.size()) {
        pii p = pq.top(); pq.pop();

        if (pq.size()) {
            pii q = pq.top(); pq.pop();
            int lp = lea[p.nd].back(); lea[p.nd].pop_back();
            int lq = lea[q.nd].back(); lea[q.nd].pop_back();
            ans.pb(mp(lp, lq));
            if (p.st-1 > 0) pq.push(mp(p.st-1, p.nd));
            if (q.st-1 > 0) pq.push(mp(q.st-1, q.nd));
        } else {
            int lp = lea[p.nd].back(); lea[p.nd].pop_back();
            ans.pb(mp(lp, c));
        }
    }

    printf("%d\n", (int) ans.size());
    for (auto p : ans) printf("%d %d\n", p.st, p.nd);
    return 0;
}
