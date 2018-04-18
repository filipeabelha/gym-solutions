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

int par[N], sz[N];
multiset <int> m;

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    m.erase(m.find(sz[a]));
    m.erase(m.find(sz[b]));
    sz[a] += sz[b];
    m.insert(sz[a]);
}

int n, q, a, b;

int main () {
    scanf("%d%d", &n, &q);

    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;

    for (int i = 1; i <= n; i++) m.insert(1);

    while (q--) {
        scanf("%d%d", &a, &b);
        unite(a, b);
        int d = *m.rbegin() - *m.begin();
        printf("%d\n", d);
    }

    return 0;
}
