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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e2+10;

int t[N][N], dp[N][N], vis[N][N], n, m;
char x;

void clean (int x, int y) {
    if (vis[x][y]) return;
    vis[x][y] = 1;
    int frstroom = INF, lastroom = 0, ans = 0, p = y;
    for (int j = 1; j <= m+2; j++) if (t[x][j]) frstroom = min(frstroom, j);
    for (int j = m+2; j >= 1; j--) if (t[x][j]) lastroom = max(lastroom, j);
    if (lastroom) {
        if      (y == 1)   ans = abs(y-lastroom), p = lastroom;
        else if (y == m+2) ans = abs(y-frstroom), p = frstroom;
    }
    if (x != 1) {
        int l = abs(p-1)+1;
        int r = abs(p-(m+2))+1;
        clean(x-1, 1);
        clean(x-1, m+2);
        ans += min((dp[x-1][1]>0)*(l+dp[x-1][1]), (dp[x-1][m+2]>0)*(r+dp[x-1][m+2]));
    }
    dp[x][y] = ans;
}

int main () {
    scanf("%d%d%c", &n, &m, &x);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m+2; j++) scanf("%c", &x), t[i][j] = x - '0';
        scanf("%c", &x);
    }
    clean(n, 1);
    printf("%d\n", dp[n][1]);
    return 0;
}
