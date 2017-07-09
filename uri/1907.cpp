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
const int N = 1e3+30;

int t[N][N], vis[N][N];

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

void dfs (int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (!vis[xx][yy] and t[xx][yy]) dfs(xx, yy);
    }
}

int n, m, ans;
char c;

int main () {
    scanf("%d%d%c", &n, &m, &c);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%c", &c);
            if (c == '.') t[i][j] = 1;
        }
        scanf("%c", &c);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[i][j] and t[i][j])
                ans++, dfs(i, j);
    printf("%d\n", ans);
    return 0;
}
