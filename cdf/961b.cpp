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

ll n, k, a[N], t[N];
ll ans;

int main () {
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &t[i]);
    for (int i = 1; i <= n; i++) {
        if (t[i]) ans += a[i], a[i] = 0;
        a[i] += a[i-1];
    }
    ll sum = 0;
    for (int i = k; i <= n; i++) sum = max(sum, a[i]-a[i-k]);
    ans += sum;
    printf("%lld\n", ans);
    return 0;
}
