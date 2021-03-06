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

ll v, a, k;
ld ans;

int main () {
    scanf("%lld%lld%lld", &v, &a, &k);
    if (v + a < k) {
        ans = 0;
    } else if (a <= k-1) {
        ans = a/(ld)k;
    } else {
        ans = (a-k+1.)/(a-k+1.+v);
        ans += k-1;
        ans /= (ld)k;
    }
    printf("%.10Lf\n", ans);
    return 0;
}
