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

vector <ll> v;
ll n, m, k, x;

int main () {
    scanf("%lld%lld%lld", &n, &m, &k);
    while (n--) scanf("%lld", &x), v.pb(x);
    sort(v.begin(), v.end());
    ll packet = k*v.back() + v[v.size()-2];
    ll ans = (m/(k+1))*packet;
    m %= (k+1);
    ans += m*v.back();
    printf("%lld\n", ans);

    return 0;
}
