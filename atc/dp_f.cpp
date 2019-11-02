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
const int N = 3e3+5;

int dp[N][N], n, m;
pii par[N][N];
string s, t;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    n = s.size();
    m = t.size();
    s = '0' + s;
    t = '0' + t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                par[i][j] = {i-1, j-1};
            } else if (dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                par[i][j] = {i-1, j};
            } else {
                dp[i][j] = dp[i][j-1];
                par[i][j] = {i, j-1};
            }
        }
    }

    string ans = "";
    int i = n;
    int j = m;

    while (i and j) {
        if (par[i][j] == mp(i-1, j-1)) ans.pb(s[i]);
        pii p = par[i][j];
        i = p.st;
        j = p.nd;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";

    return 0;
}
