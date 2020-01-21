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

ll dp0 (ll x) {
    if (x <= 2) return x;
    return !(x&1);
}

ll dp1 (ll x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 0;
    if (x == 3) return 1;
    if (x&1)    return 0;

    int cnt = 0;
    while (x % 2 == 0) {
        x /= 2;
        cnt++;
    }

    if (x == 3) {
        if (cnt&1) return 2;
        return 1;
    } else {
        if (cnt&1) return 1;
        return 2;

    }
}

ll n, k, x, ans;

int main () {
    scanf("%lld%lld", &n, &k);
    while (n--) {
        scanf("%lld", &x);
        if (k&1) ans ^= dp1(x);
        else     ans ^= dp0(x);
    }
    printf("%s\n", ans ? "Kevin" : "Nicky");


    return 0;
}
