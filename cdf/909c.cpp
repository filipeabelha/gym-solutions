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
const int N = 5e3+5;

ll dp[N][N], ans;
int n;
char c;

int main () {
    scanf("%d", &n);
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &c);
        if (c == 'f') for (int j = 2; j < N; j++) dp[i+1][j] = dp[i][j-1];
        if (c == 's') {
            ll sum = 0;
            for (int j = N-1; j > 0; j--) {
                sum += dp[i][j];
                sum %= MOD;
                dp[i+1][j] = sum;
            }
        }
    }
    for (int j = 1; j < N; j++) {
        ans += dp[n][j];
        ans %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
