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
const int N = 1e6+5;

int n, m, f[N], g[N], h[N], ok = 1;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &f[i]);
    for (int i = 1; i <= n; i++) if (f[f[i]] != f[i]) ok = 0;

    if (!ok) {
        printf("-1\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        int a = 0, b = 0;
        if (g[i]) a = g[i];
        if (g[f[i]]) b = g[f[i]];
        if (a and b and a != b) ok = 0;
        if (a == 0) swap(a, b);

        if (a) g[i] = g[f[i]] = a;
        else   g[i] = g[f[i]] = ++m;

        h[g[i]] = f[i];
    }

    if (ok) {
        printf("%d\n", m);
        for (int i = 1; i <= n; i++) printf("%d%c", g[i], " \n"[i==n]);
        for (int i = 1; i <= m; i++) printf("%d%c", h[i], " \n"[i==m]);
    } else printf("-1\n");


    return 0;
}
