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
const int N = 2e5+5;
const int M = 1e2+5;

int n, a[N], f[N];
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int dp[M][N];
vi ans[2][N];

int main () {
    cl(dp, INF);
    for (int j = 0; j < N; j++) dp[0][j] = 0;

    for (int i = 2; i <= 59; i++) {
        int fact = 0;
        for (int k = 0; k < 17; k++)
            if (p[k] <= i and i % p[k] == 0) fact |= (1 << k);
        f[i] = fact;
    }

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < N; j++) ans[0][j] = ans[1][j];
        for (int k = 1; k < 60; k++) {
            int x = (~f[k]) & ((1 << 17) - 1);
            for (int s = x; ; s = (s-1)&x) {
                if (dp[i][s|f[k]] > dp[i-1][s] + abs(a[i]-k)) {
                    dp[i][s|f[k]] = dp[i-1][s] + abs(a[i]-k);
                    ans[1][s|f[k]] = ans[0][s];
                    ans[1][s|f[k]].pb(k);
                }
                if (s == 0) break;
            }
        }
    }

    int mini = INF;
    int ind = 0;
    for (int j = 0; j < N; j++) if (mini > dp[n][j]) {
        mini = dp[n][j];
        ind = j;
    }
    for (auto z : ans[1][ind]) printf("%d ", z);
    printf("\n");

    return 0;
}
