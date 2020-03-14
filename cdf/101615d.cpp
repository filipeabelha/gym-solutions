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
const int N = 1e5+5;

int n, l, nok[N], cnt[N];
vector <pii> adj[N];

void dfs2 (int v, int vp) {
    for (auto p : adj[v]) {
        int u = p.st;
        if (u != vp) {
            nok[u] += nok[v];
            dfs2(u, v);
        }
    }
}

void dfs (int v, int vc, int vp) {
    for (auto p : adj[v]) {
        int u = p.st;
        int uc = p.nd;
        if (u == vp) continue;
        cnt[uc] = 0;
    }

    for (auto p : adj[v]) {
        int u = p.st;
        int uc = p.nd;
        if (u == vp) continue;
        cnt[uc]++;
    }

    for (auto p : adj[v]) {
        int u = p.st;
        int uc = p.nd;
        if (u == vp) continue;
        if (cnt[uc] >= 2) {
            nok[u]++;
        }
    }

    for (auto p : adj[v]) {
        int u = p.st;
        int uc = p.nd;
        if (u == vp) continue;
        if (uc == vc) {
            nok[u]++;
            nok[1]++;
            nok[v]--;
        }

        dfs(u, uc, v);
    }
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    dfs(1, -1, -1);
    dfs2(1, -1);

    vi ans;
    for (int i = 1; i <= n; i++) if (!nok[i]) ans.pb(i);
    sort(ans.begin(), ans.end());
    printf("%d\n", (int) ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
