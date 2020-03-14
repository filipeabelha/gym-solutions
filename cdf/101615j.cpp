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
const int N = 35;

ll n, m, dp[N][N];
char a[N][N];

int main () {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &a[i][j]);
        }
    }

    int ok = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1][j] == 'R' or
                a[i][j-1] == 'R' or
                a[i-1][j-1] == 'R') {

                if (a[i][j] == 'B') ok = 0;

                a[i][j] = 'R';
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (a[i+1][j] == 'B' or
                a[i][j+1] == 'B' or
                a[i+1][j+1] == 'B') {

                if (a[i][j] == 'R') ok = 0;

                a[i][j] = 'B';
            }
        }
    }

    if (!ok) {
        printf("0\n");
        return 0;
    }

    for (int i = n; i >= 1; i--) {
        int l = 0;
        int r = 0;
        for (int j = 1; j <= m; j++) {
            l += a[i][j] == 'B';
            r += a[i][j] == '.';
        }
        r += l;

        for (int j = l; j <= r; j++) {
            if (i == n) dp[n][j] = 1;
            else for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i+1][k];
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j <= m; j++) ans += dp[1][j];

    printf("%lld\n", ans);


    return 0;
}
