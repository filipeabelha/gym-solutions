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
const int N = 1e3+5;

ll n, m, ds, cs, da, ca;
ll hp[N];

bool slv (ll x) {
    for (ll i = 0; i*ca <= m; i++) {
        ll killed = 0;
        vector <ll> rem;
        for (ll j = 1; j <= n; j++) {
            ll lef = max(0ll, hp[j]-i*da);
            if (lef == 0) killed++;
            else rem.pb(-lef);
        }
        sort(rem.begin(), rem.end());
        ll k = 0;
        while (i*ca + (k+1)*cs <= m) k++;
        while (k) {
            if (rem.size() and -rem.back() <= k*ds) {
                killed++;
                k -= -rem.back()/ds + (-rem.back() % ds > 0);
                rem.pop_back();
            } else break;
        }
        if (killed >= x) return true;
    }
    return false;
}

int main () {
    scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &ds, &cs, &da, &ca);
    for (int i = 1; i <= n; i++) scanf("%lld", &hp[i]);
    ll l = 0, x, r = INF;
    while (l < r) {
        x = (l+r+1)/2;
        if (!slv(x)) r = x-1;
        else l = x;
    }
    printf("%lld\n", l);
    return 0;
}
