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

ll n, c, t, v[N];

bool ok (ll m) {
    ll need = 0;
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] > t*m) return false;
        if (cur + v[i] <= t*m) cur += v[i];
        else {
            cur = v[i];
            need++;
        }
    }
    need++;

    return need <= c;
}

int main () {
    scanf("%lld%lld%lld", &n, &c, &t);
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);

    ll l = 0, m, r = LINF/100;
    while (l < r) {
        m = (l+r)/2;
        if (!ok(m)) l = m+1;
        else        r = m;
    }

    printf("%lld\n", l);

    return 0;
}
