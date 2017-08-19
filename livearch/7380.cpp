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
const int N = 5e2+5;

int n, m, vis[N][N];
char t[N][N];
char chr;
int dx[] = {-1, +0, +0, +1};
int dy[] = {+0, -1, +1, +0};
int ans;
queue <piii> q;

int main () {
    while (~scanf("%d%d%c", &n, &m, &chr)) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                scanf("%c", &t[i][j]);
            scanf("%c", &chr);
        }
        cl(vis, 0);
        ans = 0;
        q.push(mp(0, mp(1, 1)));
        while (q.size()) {
            int d = q.front().st;
            int x = q.front().nd.st;
            int y = q.front().nd.nd; q.pop();
            if (x == n and y == m) {
                printf("%d\n", d);
                ans = 1;
            }
            for (int i = 0; i < 4; i++) {
                int xx = x+dx[i]*(t[x][y]-'0');
                int yy = y+dy[i]*(t[x][y]-'0');
                if (xx < 1 or xx > n) continue;
                if (yy < 1 or yy > m) continue;
                if (vis[xx][yy] == 1) continue;
                vis[xx][yy] = 1;
                q.push(mp(d+1, mp(xx, yy)));
            }
            if (ans) while (q.size()) q.pop();
        }
        printf("%s", ans ? "" : "-1\n");
    }
    return 0;
}
