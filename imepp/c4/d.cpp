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
const int INF = 0x3f3f3f3f, MOD = 10;
const int N = 1e5+5;

ll fexp (ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % MOD;
        b = (b*b) % MOD;
        e >>= 1;
    }
    return ans;
}

ll n;

int main () {
    scanf("%lld", &n);
    printf("%lld\n", fexp(1378, n));
    return 0;
}
