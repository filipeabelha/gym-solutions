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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 2e5+10;

int n, c, v[N], dp[N][2];

int main () {
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    dp[0][0] = 0;
    dp[0][1] = -v[0]-c;
    for (int i = 1; i <= n; i++) {
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]-v[i-1]-c);
        dp[i][0] = max(dp[i-1][1]+v[i-1], dp[i-1][0]);
    }
    printf("%d\n", dp[n][0]);
    return 0;
}
