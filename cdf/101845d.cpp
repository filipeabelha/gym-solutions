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

ll n, m, x[N], y[N], acc[N], a, b, sum, ans;

int main () {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &x[i], &y[i]);
    }

    acc[2] = x[1]*y[2]-x[2]*y[1];
    for (int i = 3; i <= n; i++) {
        acc[i] = acc[i-1] + x[i-1]*y[i] - x[i]*y[i-1];
    }

    sum = abs(acc[n] + x[n]*y[1] - x[1]*y[n]);

    while (m--) {
        scanf("%lld%lld", &a, &b);
        ll k = abs(acc[b] - acc[a] + x[b]*y[a] - x[a]*y[b]);
        ans = max(ans, min(k, sum-k));
    }

    printf("%lld.%lld\n", ans/2, (ll) 5*(ans&1ll));
    return 0;
}
