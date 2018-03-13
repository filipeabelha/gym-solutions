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
const ll M = 1000000000ll;

ll a[N], b[N];
ll mxl, mxc, x = 1, y = 1, z = 1;

int n, m;

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int j = 1; j <= m; j++) scanf("%lld", &b[j]);
    for (int i = 1; i <= n; i++) {
        if (mxl < a[i]) {
            mxl = a[i];
            x = y = i;
        } else if (mxl == a[i]) y = i;
    }
    for (int j = 1; j <= m; j++) {
        if (mxc < b[j]) {
            mxc = b[j];
            z = j;
        }
    }
    ll ans = 0;
    for (int i = 1; i < x; i++)  ans += M*a[i]+b[1];
    for (int j = 1; j < z; j++)  ans += M*a[x]+b[j];
    for (int i = x; i < y; i++)  ans += M*a[i]+b[z];
    for (int j = z; j < m; j++)  ans += M*a[y]+b[j];
    for (int i = y; i <= n; i++) ans += M*a[i]+b[m];

    printf("%lld\n", ans);
    return 0;
}
