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
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll n, m;
ll x[N], y[N];
ll ans;

int main () {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
    for (int i = 1; i <= m; i++) scanf("%lld", &y[i]);
    ll a = 0;
    ll b = 1;
    ll sa = 0;
    ll sb = y[1];
    while (1) {
        if (sb >= sa) {
            a++;
            sa += x[a];
        } else if (sb < sa) {
            b++;
            sb += y[b];
        }

        if (sa == sb) ans++;
        if (a > n or b > m) break;
    }
    printf("%lld\n", ans-1);
    return 0;
}
