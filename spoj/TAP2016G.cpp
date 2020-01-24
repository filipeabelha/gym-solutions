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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, a, b, w, sxor[N], vis[N];
vector <pii> adj[N];

void dfs (int v) {
    if (vis[v]) return;
    vis[v] = 1;
    for (auto p : adj[v]) {
        int u = p.st;
        int d = p.nd;
        sxor[u] = sxor[v]^d;
        dfs(u);
    }
}

struct Node {
    Node* ch[2];

    Node () {
        ch[0] = ch[1] = nullptr;
    }
};

int main () {
    while (~scanf("%d", &n)) {
        memset(sxor, 0, sizeof sxor);
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < N; i++) adj[i].clear();

        for (int i = 0; i < n-1; i++) {
            scanf("%d%d%d", &a, &b, &w);
            adj[a].pb({b, w});
            adj[b].pb({a, w});
        }

        dfs(1);

        Node* root = new Node();

        for (int i = 1; i <= n; i++) {
            ll x = sxor[i];
            Node* cur = root;
            for (ll j = 30; j >= 0; j--) {
                ll b = (((1ll << j)&x) > 0);
                if (!cur->ch[b]) cur->ch[b] = new Node();
                cur = cur->ch[b];
            }
        }

        for (int i = 1; i <= n; i++) {
            ll x = sxor[i];
            Node* cur = root;
            ll ans = 0;
            for (ll j = 30; j >= 0; j--) {
                ll b = (((1ll << j)&x) > 0);
                if (cur->ch[!b]) {
                    cur = cur->ch[!b];
                    ans += (1ll << j);
                } else cur = cur->ch[b];
            }
            printf("%lld\n", ans);
        }

        delete root;
    }

    return 0;
}
