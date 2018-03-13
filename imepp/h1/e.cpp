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
const int N = 1e2+5;

int n, m, f, x, y, ans, vis[N][N];
char t[N][N], c, dir;

bool ok (int u, int v) {
    if (u < 1 or u > n) return false;
    if (v < 1 or v > m) return false;
    if (t[u][v] == '#') return false;
    return true;
}

void go (char c) {
    if      (c == 'D' and dir == 'N') dir = 'L';
    else if (c == 'D' and dir == 'L') dir = 'S';
    else if (c == 'D' and dir == 'S') dir = 'O';
    else if (c == 'D' and dir == 'O') dir = 'N';

    else if (c == 'E' and dir == 'N') dir = 'O';
    else if (c == 'E' and dir == 'O') dir = 'S';
    else if (c == 'E' and dir == 'S') dir = 'L';
    else if (c == 'E' and dir == 'L') dir = 'N';

    if (c == 'D' or c == 'E') return;

    int u = x - (dir == 'N') + (dir == 'S');
    int v = y - (dir == 'O') + (dir == 'L');

    if (ok(u, v)) {
        x = u;
        y = v;
        if (t[x][y] == '*' and !vis[x][y]) vis[x][y] = 1, ans++;
    }
}

int main () {
    while (~scanf(" %d %d %d", &n, &m, &f) and (n or m or f)) {
        cl(vis, 0);
        ans = 0;

        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
            scanf(" %c", &t[i][j]);
            if (t[i][j] == 'N' or
                t[i][j] == 'S' or
                t[i][j] == 'L' or
                t[i][j] == 'O')
                x = i, y = j, dir = t[i][j];
        }

        while (f--) {
            scanf(" %c", &c);
            go(c);
        }
        printf("%d\n", ans);
    }
    return 0;
}
