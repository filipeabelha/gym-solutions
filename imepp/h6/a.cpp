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
const int N = 3e3+5;

int n, a, b, c, dp[N][N], mx[N][N];

int main () {
    while (~scanf("%d", &n) and n) {
        cl(dp, 0);
        cl(mx, 0);

        while (n--) {
            scanf("%d%d%d", &a, &b, &c);

            dp[a][b] = max(dp[a][b], c);
            dp[b][a] = max(dp[b][a], c);

            dp[a][c] = max(dp[a][c], b);
            dp[c][a] = max(dp[c][a], b);

            dp[b][c] = max(dp[b][c], a);
            dp[c][b] = max(dp[c][b], a);
        }

        for (int i = 1; i < N; i++)
            for (int j = 1; j < N; j++) {
                dp[i][j] += mx[i-1][j-1];
                mx[i][j] = max(dp[i][j], max(mx[i-1][j], mx[i][j-1]));
            }

        printf("%d\n", dp[N-1][N-1]);
    }
    return 0;
}
