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
const int N = 5e2+5;

int n, m, q, a, b, age[N], id[N], idr[N], vis[N], cnt;
vi adj[N];

int dfs (int v) {
    if (vis[v] == cnt) return INF;
    vis[v] = cnt;

    int ans = INF;
    for (auto u : adj[v]) {
        ans = min(ans, min(age[idr[u]], dfs(u)));
    }
    return ans;
}

int main () {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &age[i]);
        id[i] = idr[i] = i;
    }

    while (m--) {
        scanf("%d%d", &a, &b);
        adj[b].pb(a);
    }

    while (q--) {
        char c;
        scanf(" %c", &c);
        if (c == 'P') {
            scanf("%d", &a);

            cnt++;
            int val = dfs(id[a]);
            if (val < INF) printf("%d\n", val);
            else printf("*\n");
        } else {
            scanf("%d%d", &a, &b);
            swap(idr[id[a]], idr[id[b]]);
            swap(id[a], id[b]);
        }
    }

    return 0;
}
