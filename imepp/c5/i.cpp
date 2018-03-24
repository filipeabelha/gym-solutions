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
const int N = 50;

int n, m, vis[N][N];
char dirx[N], diry[N];
bool ok = true;

int dx[]  = {+0, +0, +1, -1};
int dy[]  = {+1, -1, +0, +0};
char dd[] = {'>', '<', 'v', '^'};

void dfs (int i, int j) {
    if (vis[i][j]) return;
    vis[i][j] = 1;

    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x < 1 or x > n) continue;
        if (y < 1 or y > m) continue;
        if (dd[k] != dirx[i] and dd[k] != diry[j]) continue;
        dfs(x, y);
    }
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf(" %c", &dirx[i]);
    for (int i = 1; i <= m; i++) scanf(" %c", &diry[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cl(vis, 0);
            dfs(i, j);
            for (int a = 1; a <= n; a++)
                for (int b = 1; b <= m; b++)
                    if (!vis[a][b]) ok = false;
        }

    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}
