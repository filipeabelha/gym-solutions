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
const int N = 1e5+5;

string s;
int dp[N][3];

int main () {
    cin >> s;
    s = " " + s;
    for (int i = 1; i < s.size(); i++) {
        dp[i][0] = dp[i-1][0] + (s[i] == 'a');
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]) + (s[i] == 'b');
        dp[i][2] = max(dp[i-1][2], dp[i-1][1]) + (s[i] == 'a');
    }
    int n = s.size()-1;
    printf("%d\n", max(dp[n][0], max(dp[n][1], dp[n][2])));
    return 0;
}
