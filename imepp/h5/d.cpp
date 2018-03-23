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

int n, m, a, b, cnt, par[N], sz[N];

int find (int x) { return par[x] == x ? x : x = find(par[x]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

int main () {
    while (~scanf("%d%d", &n, &m) and n and m and ++cnt) {
        for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
        while (m--) {
            scanf("%d%d", &a, &b);
            unite(a, b);
        }
        int ok = 1;
        for (int i = 2; i <= n; i++) if (find(i) != find(1)) ok = 0;
        printf("Teste %d\n%s\n\n", cnt, ok ? "normal" : "falha");
    }
    return 0;
}
