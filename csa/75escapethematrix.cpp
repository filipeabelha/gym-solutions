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
const int N = 5e2+5;

char t[N][N];
int n, m, ans, can[N][N], vis[N][N];

void calc (int i, int j) {
    if (vis[i][j]) return;
    vis[i][j] = 1;

    if (t[i][j] == 'D' and i == n) { can[i][j] = 1; return; }
    if (t[i][j] == 'U' and i == 1) { can[i][j] = 1; return; }
    if (t[i][j] == 'R' and j == m) { can[i][j] = 1; return; }
    if (t[i][j] == 'L' and j == 1) { can[i][j] = 1; return; }

    if (t[i][j] == 'D') {if (!vis[i+1][j]) calc(i+1, j); can[i][j] = can[i+1][j]; return; }
    if (t[i][j] == 'U') {if (!vis[i-1][j]) calc(i-1, j); can[i][j] = can[i-1][j]; return; }
    if (t[i][j] == 'R') {if (!vis[i][j+1]) calc(i, j+1); can[i][j] = can[i][j+1]; return; }
    if (t[i][j] == 'L') {if (!vis[i][j-1]) calc(i, j-1); can[i][j] = can[i][j-1]; return; }
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        scanf(" %c", &t[i][j]);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        calc(i, j);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) ans += can[i][j];

    printf("%d\n", ans);
    return 0;
}
