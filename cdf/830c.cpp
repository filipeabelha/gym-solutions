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
typedef vector<ll> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e2+5;

ll n, k, a[N], s;
vll vd;

int main () {
    scanf("%lld%lld", &n, &k);
    s = k;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        for (ll j = 1; j*j <= a[i]; j++) {
            vd.pb(j);
            vd.pb((a[i]-1)/j + 1);
        }
        s += a[i];
    }
    sort(vd.begin(), vd.end());
    vd.erase(unique(vd.begin(), vd.end()), vd.end());

    ll ans = 0;
    for (int i = vd.size()-1; i >= 0; i--) {
        ll d = vd[i];
        ll sum = 0;
        for (int j = 1; j <= n; j++) sum += (a[j]-1)/d + 1;
        if (d <= s/sum) {
            ans = max(ans, s/sum);
        }
    }
    printf("%lld\n", ans);

    return 0;

}
