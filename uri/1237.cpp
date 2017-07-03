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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e2;

string s, t;
int dp[N][N], ans;

int main () {
    while (getline(cin, s)) {
        getline(cin, t);
        cl(dp, 0);
        ans = 0;
        for (int i = 1; i <= s.size(); i++)
            for (int j = 1; j <= t.size(); j++) {
                if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                ans = max(ans, dp[i][j]);
            }
        printf("%d\n", ans);
    }
    return 0;
}
