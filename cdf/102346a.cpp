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
const int N = 1e3+5;

ll a, b, x, y, k, r;

struct Circ {
    ll x;
    ll y;
    ll r;
};

vector <Circ> c;

int par[N], sz[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

int main () {
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
    scanf("%lld%lld%lld", &a, &b, &k);
    c.resize(k);
    for (int i = 0; i < k; i++) {
        scanf("%lld%lld%lld", &c[i].x, &c[i].y, &c[i].r);
    }
    for (int i = 0; i < k; i++) {
        for (int j = i+1; j < k; j++) {
            ll dx = c[i].x - c[j].x;
            ll dy = c[i].y - c[j].y;
            ll sr = c[i].r + c[j].r;
            if (dx*dx + dy*dy <= sr*sr) unite(i, j);
        }
    }
    for (int i = 0; i < k; i++) {
        if (c[i].x - c[i].r <= 0) unite(i, k);
        if (c[i].y - c[i].r <= 0) unite(i, k+1);
        if (c[i].x + c[i].r >= a) unite(i, k+2);
        if (c[i].y + c[i].r >= b) unite(i, k+3);
    }

    int ans = 0;
    if (find(k) == find(k+1))   ans = 1;
    if (find(k) == find(k+2))   ans = 1;
    if (find(k+1) == find(k+3)) ans = 1;
    if (find(k+2) == find(k+3)) ans = 1;

    printf("%s\n", ans ? "N" : "S");

    return 0;
}

