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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 3e3;

char chr, w[N];
int n, x, len, spec[N], dp[N][N][2];
vector <pii> sub;

int main () {
    scanf("%s%c%d", w, &chr, &n);
    len = strlen(w);
    while (n--) scanf("%d", &x), spec[x-1] = 1;
    for (int sz = 0; sz < len; sz++) for (int l = 0; l < len; l++) {
        int r = l+sz;
        if (r >= len) continue;
        if (l == r) {
            dp[l][r][0] = spec[l];
            dp[l][r][1] = 1;
        } else {
            sub.clear();
            if (w[l] == w[r])
                sub.pb(mp(spec[l]+spec[r]+dp[l+1][r-1][0], 2+dp[l+1][r-1][1]));
            sub.pb(mp(dp[l+1][r][0], dp[l+1][r][1]));
            sub.pb(mp(dp[l][r-1][0], dp[l][r-1][1]));
            sort(sub.begin(), sub.end());
            dp[l][r][0] = sub[sub.size()-1].st;
            dp[l][r][1] = sub[sub.size()-1].nd;
        }
    }
    printf("%d\n", dp[0][len-1][1]);
    return 0;
}
