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
const int N = 1e3+5;

int n, cnt, v[N], memo[N][N][2];

int dp (int i, int j, int k) {
    if (memo[i][j][k] != INF) return memo[i][j][k];
    if (k == 0 and i == j) return memo[i][j][k] = -v[i];
    if (k == 1 and i == j) return memo[i][j][k] = v[i];
    if (k == 0) return memo[i][j][k] = min(-v[i] + dp(i+1, j, 1^k),
                                           -v[j] + dp(i, j-1, 1^k));
    if (v[i] >= v[j]) return memo[i][j][k] = v[i] + dp(i+1, j, 1^k);
                      return memo[i][j][k] = v[j] + dp(i, j-1, 1^k);
}

int main () {
    while (~scanf("%d", &n) and n and ++cnt) {
        cl(v, 0);
        cl(memo, 63);

        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", cnt, -dp(0, n-1, 0));
    }
    return 0;
}
