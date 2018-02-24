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
const int N = 1e2+5;

int n, d, x, ans;

vi v;

int dp[N][N];

int main () {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        v.pb(x);
    }
    cl(dp, 63);
    sort(v.begin(), v.end());
    for (int j = 0; j < n; j++) {
        for (int i = n-1; i >= 0; i--) {
            if (v[j] - v[i] <= d or i == j) dp[i][j] = 0;
            else dp[i][j] = 1+min(dp[i][j-1], dp[i+1][j]);
        }
    }
    printf("%d\n", dp[0][n-1]);
    return 0;
}
