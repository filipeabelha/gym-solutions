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
const int N = 50+5;

int n, m, ans, t[N][N], vis[N][N];
queue <piii> q;

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

int main () {
    cl(t, -1);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &t[i][j]);
            if (t[i][j] == 3) {
                vis[i][j] = 1;
                q.push({0, {i, j}});
            }
        }

    while (q.size()) {
        piii p = q.front(); q.pop();
        int d = p.st;
        int a = p.nd.st;
        int b = p.nd.nd;
        if (!t[a][b]) {
            ans = d;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int x = a+dx[i];
            int y = b+dy[i];
            if (x < 1 or x > n) continue;
            if (y < 1 or y > m) continue;
            if (t[x][y] == 2) continue;
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            q.push({d+1, {x, y}});
        }
    }
    printf("%d\n", ans);
    return 0;
}
