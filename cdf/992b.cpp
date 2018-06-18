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
const int N = 1e6+10;

ll lcm (ll a, ll b) {return a*b/gcd(a, b);}

set <pll> ans;
ll l, r, x, y;

bool valid (ll a, ll b) {
    if (a < l or a > r) return false;
    if (b < l or b > r) return false;
    if (gcd(a, b) != x) return false;
    if (lcm(a, b) != y) return false;
    return true;
}

int main () {
    scanf("%lld%lld%lld%lld", &l, &r, &x, &y);

    for (ll i = 1; i*i <= x; i++) {
        if (x % i == 0) {
            if (valid(x/i, y*i)) ans.insert({x/i, y*i});
            if (valid(y*i, x/i)) ans.insert({y*i, x/i});

            if (valid(i, x*y/i)) ans.insert({i, x*y/i});
            if (valid(x*y/i, i)) ans.insert({x*y/i, i});
        }
    }

    for (ll i = 1; i*i <= y; i++) {
        if (y % i == 0) {
            if (valid(y/i, x*i)) ans.insert({y/i, x*i});
            if (valid(x*i, y/i)) ans.insert({x*i, y/i});

            if (valid(i, x*y/i)) ans.insert({i, x*y/i});
            if (valid(x*y/i, i)) ans.insert({x*y/i, i});
        }
    }

    printf("%lld\n", (ll) ans.size());

    return 0;
}
