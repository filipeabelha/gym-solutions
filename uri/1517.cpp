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
const int N = 30;
const int K = 2e3+100;

int dp[N][N][K], freq[N][N][K];
int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1, +0};
int dy[] = {+1, -1, +0, +0, -1, +1, +1, -1, +0};

int n, m, k, x, y, a, b, c;

int main () {
    while (~scanf("%d%d%d", &n, &m, &k) and n and m and k) {
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
            for (int l = 0; l < K; l++) dp[i][j][l] = -INF;
        cl(freq, 0);

        for (int i = 0; i < k; i++) {
            scanf("%d%d%d", &a, &b, &c);
            freq[a][b][c]++;
        }
        scanf("%d%d", &x, &y);
        dp[x][y][0] = 0;
        for (int t = 0; t < K; t++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++) {
                    int mx = 0;
                    for (int z = 0; z < 9; z++) {
                        int x = i+dx[z];
                        int y = j+dy[z];
                        if (x < 1 or x > n) continue;
                        if (y < 1 or y > m) continue;
                        dp[i][j][t] = max(dp[i][j][t], dp[x][y][t-1]);
                    }
                    dp[i][j][t] += freq[i][j][t];
                }
        printf("%d\n", dp[1][1][K-1]);
    }
    return 0;
}
