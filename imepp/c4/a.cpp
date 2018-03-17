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
const int N = 1e3+5;

int n, m, c;
char t[N][N];
int vis[N][N], cnt[N][N];

void go (int x, int y, int i, int j) {
    if (x < 1 or x > n or y < 1 or y > m) {
        printf("%d step(s) to exit\n", cnt[i][j]+1);
        return;
    }
    if (vis[x][y]) {
        printf("%d ", cnt[x][y]);
        printf("step(s) before a loop of ");
        printf("%d step(s)\n", cnt[i][j]+1-cnt[x][y]);
        return;
    }
    vis[x][y] = 1;
    cnt[x][y] = cnt[i][j]+1;
    if (t[x][y] == 'N') go(x-1, y, x, y);
    if (t[x][y] == 'S') go(x+1, y, x, y);
    if (t[x][y] == 'W') go(x, y-1, x, y);
    if (t[x][y] == 'E') go(x, y+1, x, y);
}

int main () {
    while (~scanf("%d%d%d", &n, &m, &c) and n and m and c) {
        cl(vis, 0);
        cl(cnt, 0);
        cl(t, 0);
        cnt[0][0] = -1;

        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
            scanf(" %c", &t[i][j]);

        go(1, c, 0, 0);
    }
    return 0;
}
