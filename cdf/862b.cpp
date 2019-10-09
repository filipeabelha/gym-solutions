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

ll n, a, b, vis[N], clr[N];
vector <ll> adj[N];

void dfs (ll v) {
    if (vis[v]) return;
    vis[v] = 1;

    for (auto u : adj[v]) {
        clr[u] = clr[v]^1;
        dfs(u);
    }
}

int main () {
    scanf("%lld", &n);
    for (int i = 0; i < n-1; i++) {
        scanf("%lld%lld", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1);

    ll k = 0;
    for (int i = 1; i < N; i++) k += clr[i];

    ll ans = k*(n-k);
    ans -= n-1;
    printf("%lld\n", ans);

    return 0;
}
