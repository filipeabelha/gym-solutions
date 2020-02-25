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

ll n, p;

ld solve (ll x) {
    ld ans = p*x;
    ans /= n+x;
    for (ll i = 0; i <= p-2; i++) {
        ans /= n+(x-1)-i;
        ans *= n-i;
    }
    return ans;
}


int main () {
    scanf("%lld%lld", &n, &p);

    for (int i = 0; ; i++) {
        if (solve(i) > solve(i+1)) {
            printf("%.7Lf\n", solve(i));
            return 0;
        }
    }

    return 0;
}
