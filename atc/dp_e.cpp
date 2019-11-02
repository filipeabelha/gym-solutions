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
const int N = 1e2+5;
const int K = 1e5+5;

int n, c, w[N], v[N], dp[K];

int main () {
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) scanf("%d%d", &w[i], &v[i]);

    cl(dp, 63);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int u = K-1; u >= v[i]; u--) {
            dp[u] = min(dp[u], dp[u-v[i]] + w[i]);
        }
    }

    int ans = 0;
    for (int u = 0; u < K; u++) if (dp[u] <= c) ans = max(ans, u);
    printf("%d\n", ans);

    return 0;
}
