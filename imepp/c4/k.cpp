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
const int N = 1e5+5;

map <ll, ll> m;
vector <pll> v;
ll n, d, x, y, ans;

ll findind (ll k) {
    pll p = {k, LINF};
    return lower_bound(v.begin(), v.end(), p) - v.begin();
}

int main () {
    scanf("%lld%lld", &n, &d);
    while (n--) {
        scanf("%lld%lld", &x, &y);
        m[x] += y;
    }
    v.pb({-LINF, 0});
    for (auto p : m) v.pb(p);
    for (int i = 1; i < v.size(); i++) v[i].nd += v[i-1].nd;

    for (ll i = 0; i < v.size(); i++) {
        ll a = i;
        ll b = findind(v[i].st-d);
        ll p = v[a].nd;
        ll q = v[b-1].nd;
        ans = max(ans, p-q);
    }
    printf("%lld\n", ans);
    return 0;
}
