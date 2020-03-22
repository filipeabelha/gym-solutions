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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

ll t, n, k, v[N];

bool ok (ll x) {
    ll cnt = 1;
    ll curmax = v[1];
    ll curqtd = 1;
    if (v[1] > x) return false;

    for (int i = 2; i <= n; i++) {
        if ((curqtd+1)*max(curmax, v[i]) <= x) {
            curmax = max(curmax, v[i]);
            curqtd++;
        } else {
            cnt++;
            curmax = v[i];
            curqtd = 1;
            if (v[i] > x) return false;
        }
    }

    return cnt <= k;
}

int main () {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
        ll l = 1, m, r = LINF;
        while (l < r) {
            m = (l+r)/2;
            if (!ok(m)) l = m+1;
            else r = m;
        }
        printf("%lld\n", l);
    }

    return 0;
}
