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

ll dp[N];
vector <pair<pll, pll>> u;

int main () {
    ll n;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        ll w, s, v;
        scanf("%lld%lld%lld", &w, &s, &v);
        u.pb({{s+w, w}, {s, v}});
    }

    sort(u.begin(), u.end());

    for (int i = 0; i < n; i++) {
        ll w = u[i].st.nd;
        ll s = u[i].nd.st;
        ll v = u[i].nd.nd;
        for (int j = s; j >= 0; j--)
            dp[j+w] = max(dp[j+w], dp[j]+v);
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) ans = max(ans, dp[i]);

    printf("%lld\n", ans);

    return 0;
}
