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
#define gcd(x, y) __gcd((x), (y))

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

int n, k, m;

int par[N], sz[N], mi[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
    mi[a] = min(mi[a], mi[b]);
}

map <string, int> id;
map <int, string> idt;

char s[N];
int cnt, x, z;
ll ans;

int main () {
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1, mi[i] = INF;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %s", s);
        if (!id.count(s)) {
            id[s] = ++cnt;
            idt[cnt] = s;
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &x);
        mi[i] = x;
    }
    for (int i = 0; i < k; i++) {
        scanf(" %d", &z);
        vi v;
        while (z--) {
            scanf(" %d", &x);
            v.pb(x);
        }
        for (int j = 1; j < v.size(); j++)
            unite(v[j], v[0]);
    }
    for (int i = 0; i < m; i++) {
        scanf(" %s", s);
        ans += mi[find(id[s])];
    }
    printf("%lld\n", ans);
}
