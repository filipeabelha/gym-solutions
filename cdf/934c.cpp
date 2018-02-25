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
const int N = 2e3+5;

int n, x, dp[N][N];

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x == 1) {
            dp[i][0] = 1+dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = 1+max(dp[i-1][1], dp[i-1][2]);
            dp[i][3] = dp[i-1][3];
        } else if (x == 2) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = 1+max(dp[i-1][0], dp[i-1][1]);
            dp[i][2] = dp[i-1][2];
            dp[i][3] = 1+max(dp[i-1][2], dp[i-1][3]);
        }
    }
    printf("%d\n", max(max(dp[n][0], dp[n][1]), max(dp[n][2], dp[n][3])));
    return 0;
}
