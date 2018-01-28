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
const int N = 1e5+5;

ll dp[11][11][70], q, b, l, r;

ll go (int i, int j, int k) {
    if (j > i or j < 0) return 0;
    if (!j and !k) return 1;
    if (j and !k) return 0;
    if (dp[i][j][k] >= 0) return dp[i][j][k];
    return dp[i][j][k] = j*go(i, j-1, k-1) + (i-j)*go(i, j+1, k-1);
}

ll solve (ll b, ll x) {
    if (!x) return 0;
    vi v;
    while (x) {
        v.pb(x%b);
        x /= b;
    }
    reverse(v.begin(), v.end());
    vi freq(b,0);
    ll ans = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = (i == 0 ? 1 : 0); j < v[i]; j++) {
            freq[j]++;
            int odd = 0;
            for (auto a : freq)
                odd += a % 2;
            ans += go(b, odd, v.size() - i - 1);
            freq[j]--;
        }
        freq[v[i]]++;
    }
    for (int i = 1; i < v.size(); i++) {
        ans += (b-1) * go(b, 1, i - 1);
    }
    int odd = 0;
    for (auto a : freq)
        odd += a % 2;
    if (odd == 0)
        ans++;
    return ans;
}

int main () {
    cl(dp, -1);
    scanf("%lld", &q);
    while (q--) {
        scanf("%lld%lld%lld", &b, &l, &r);
        printf("%lld\n", solve(b, r) - solve(b, l-1));
    }
    return 0;
}
