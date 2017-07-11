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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int n;
ll dp[N][7];
ll v[N];

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 7; j++) dp[i][j] = dp[i-1][j];
        for (int j = 0; j < 7; j++) {
            ll val = dp[i-1][j]+v[i];
            ll mod = val % 7;
            dp[i][mod] = max(dp[i][mod], val);
        }
    }
    printf("%lld\n", dp[n][0]);
    return 0;
}
