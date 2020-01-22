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

ll sum (ll x) {
    ll ans = 0;
    while (x) {
        ans += x%10;
        x /= 10;
    }
    return ans;
}

ll solve (ll x) {
    if (x <= 0) return 0;
    if ((x+1)%10 != 0) return sum(x) + solve(x-1);
    return 45*(x/10+1) + 10*solve(x/10);
}

int main () {
    ll tc;
    scanf("%lld", &tc);
    while (tc--) {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        printf("%lld\n", solve(b) - solve(a-1));
    }


    return 0;
}
