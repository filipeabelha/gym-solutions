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
const int N = 1e5+5;

ll n, k, a, b, ans;

ll slv (ll u) {
    if (k == 1) return (u-1)*a;
    if (u == 1) return 0;
    if (u < k) return (u-1)*a;
    if (u % k == 0) return min(b, a*(u-u/k)) + slv(u/k);
    ll v = k*(u/k);
    return a*(u-v) + slv(v);
}

int main () {
    scanf("%lld%lld%lld%lld", &n, &k, &a, &b);
    printf("%lld\n", slv(n));
    return 0;
}
