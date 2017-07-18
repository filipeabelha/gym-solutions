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
const int N = 5e3+5;

int n, v[N], w[N], dp[N], targ;

int main () {
    while (~scanf("%d", &n) and n) {
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &v[i], &w[i]);
        cl(dp, 0);
        scanf("%d", &targ);
        for (int i = 1; i <= n; i++)
            for (int j = N-1; j >= w[i]; j--)
                dp[j] = max(dp[j], v[i]+dp[j-w[i]]);
        printf("%d\n", dp[targ]);
    }
    return 0;
}
