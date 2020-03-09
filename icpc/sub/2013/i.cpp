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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e3+5;

int n, c, a, b, x, memo[N], ans = INF;
vi v;

int dp (int i) {
    if (~memo[i]) return memo[i];
    int posa = lower_bound(v.begin(), v.end(), v[i]+a+1) - v.begin();
    int posb = lower_bound(v.begin(), v.end(), v[i]+b+1) - v.begin();
    return memo[i] = min(a + (posa < n ? dp(posa) : 0),
                         b + (posb < n ? dp(posb) : 0));
}

int main () {
    scanf("%d%d%d%d", &n, &c, &a, &b);
    v.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    for (int i = 0; i < n; i++) {
        cl(memo, -1);
        ans = min(ans, dp(0));
        v.pb(v[0]+c);
        v.erase(v.begin());
    }

    printf("%d\n", ans);

    return 0;
}
