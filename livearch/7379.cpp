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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair <ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

ll n, x, y, r, ok, dir[N];
plll g[N];

ll dis (plll a, plll b) {
    return (a.nd.st-b.nd.st)*(a.nd.st-b.nd.st) + (a.nd.nd-b.nd.nd)*(a.nd.nd-b.nd.nd);
}

ll gcd (ll a, ll b) { return b ? gcd(b, a%b) : a;}

int tang (int a, int b) {
    return (dis(g[a], g[b]) == (g[a].st+g[b].st)*(g[a].st+g[b].st));
}

int main () {
    while (~scanf("%lld", &n)) {
        cl(dir, 0);
        ok = 1;
        dir[0] = 1;
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld%lld", &x, &y, &r);
            g[i].st = r;
            g[i].nd.st = x;
            g[i].nd.nd = y;
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j and tang(i, j)) {
            if (!dir[j]) dir[j] = -dir[i];
            else if (dir[i] == dir[j]) ok = 0;
        }
        ll u = g[0].st;
        ll v = g[n-1].st;
        if (!ok) printf("-1\n");
        else if (dir[n-1]) printf("%lld %lld\n", v/gcd(u, v), dir[n-1]*u/gcd(u, v));
        else printf("0\n");
    }
    return 0;
}
