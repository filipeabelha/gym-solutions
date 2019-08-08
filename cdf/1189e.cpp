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
const int N = 3e5+5;

ll n, p, k, x, ans;
map <ll, ll> f;

int main () {
    scanf("%lld%lld%lld", &n, &p, &k);
    while (n--) {
        scanf("%lld", &x);
        ll a = (x*x % p);
        a *= a; a %= p;
        a -= k*x; a %= p;
        a += p; a %= p;
        f[a]++;
    }
    for (auto p : f) {
        ll m = p.nd;
        ans += m*(m-1)/2;
    }
    printf("%lld\n", ans);
    return 0;
}
