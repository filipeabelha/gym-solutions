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
const int N = 2e3+5;

int tc, memo[N][N];
string s, t;

int dp (int i, int j) {
    if (~memo[i][j]) return memo[i][j];
    if (!i or !j) return memo[i][j] = max(i, j);
    if (s[i-1] == t[j-1]) return memo[i][j] = dp(i-1, j-1);
    return memo[i][j] = 1 + min(dp(i-1, j-1), min(dp(i-1, j), dp(i, j-1)));
}

int main () {
    scanf("%d", &tc);
    while (tc--) {
        cl(memo, -1);
        cin >> s >> t;
        printf("%d\n", dp(s.size(), t.size()));
    }
    return 0;
}
