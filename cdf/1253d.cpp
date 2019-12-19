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
const int N = 2e5+5;

set <int> parents;

int par[N], sz[N], mn[N], mx[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    mn[a] = min(mn[a], mn[b]);
    mx[a] = max(mx[a], mx[b]);
    sz[a] += sz[b];
    parents.erase(b);
    par[b] = a;
}

int main () {
    for (int i = 0; i < N; i++) {
        par[i] = mn[i] = mx[i] = i, sz[i] = 1;
    }
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) parents.insert(i);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        unite(a, b);
    }

    vector <pii> v;

    for (auto x : parents) {
        int l = mn[x];
        int r = mx[x];
        v.pb({l, 1});
        v.pb({r, 2});
    }

    ll cur = 0;
    ll ans = 0;
    sort(v.begin(), v.end());
    for (auto p : v) {
        int x = p.st;
        int m = p.nd;

        if (m == 1) ans += (cur > 0), cur++;
        else cur--;
    }
    printf("%lld\n", ans);

    return 0;
}
