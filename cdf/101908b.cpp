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
const int N = 1e2+5;

int memo[N][N];

int mex (vi& v) {
    for (int ans = 0; ; ans++) {
        if (!binary_search(v.begin(), v.end(), ans)) return ans;
    }
    return -1;
}


bool valid (int i, int j) {
    return i > 0 and j > 0 and i != j;
}

int dp (int i, int j) {
    if (memo[i][j] != -1) return memo[i][j];
    vi v;
    for (int u = 1; u < max(i, j); u++) {
        if (valid(i-u, j))   v.pb(dp(i-u, j));
        if (valid(i, j-u))   v.pb(dp(i,   j-u));
        if (valid(i-u, j-u)) v.pb(dp(i-u, j-u));
    }
    sort(v.begin(), v.end());
    return memo[i][j] = v.size() ? mex(v) : 0;
}


int main () {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            memo[i][j] = -1;

    int n, x, y, ok = 0, ans = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &x, &y);
        if (x == 0 or y == 0 or x == y) {
            ok = 1;
        }
        ans ^= dp(x, y);
    }
    printf("%c\n", ok or ans ? 'Y' : 'N');

    return 0;
}
