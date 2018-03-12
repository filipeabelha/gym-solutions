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
const int N = 1e3+5;

int n, m, d[N][N][4], ans = INF;
bool e[5][5];
char t[N][N];
queue <pii> q;

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

bool isNumber (char c) {
    return (c >= '1' and c <= '3');
}

void dfs (int a, int b, int s) {
    if (!d[a][b][s]) return;
    d[a][b][s] = 0;

    for (int i = 0; i < 4; i++) {
        int x = a + dx[i];
        int y = b + dy[i];
        if (x < 1 or x > n) continue;
        if (y < 1 or y > m) continue;
        if (t[x][y] == '.') continue;
        if (t[x][y] == '#') continue;
        dfs(x, y, s);
    }
}

void bfs (int s) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        if (d[i][j][s] == 0) {
            q.push({i, j});
        }

    while (q.size()) {
        pii p = q.front(); q.pop();
        int a = p.st;
        int b = p.nd;
        for (int i = 0; i < 4; i++) {
            int x = a+dx[i];
            int y = b+dy[i];
            if (x < 1 or x > n) continue;
            if (y < 1 or y > m) continue;
            if (t[x][y] == '#') continue;
            if (t[x][y] == t[a][b] and isNumber(t[x][y]) and d[x][y][s] > d[a][b][s]) {
                d[x][y][s] = d[a][b][s];
                q.push({x, y});
            } else if (d[x][y][s] > d[a][b][s] + 1) {
                d[x][y][s] = d[a][b][s] + 1;
                q.push({x, y});
            }
        }
    }
}

int main () {
    cl(d, 63);
    cl(e, 0);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        scanf(" %c", &t[i][j]);

    for (int k = 1; k <= 3; k++) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (t[i][j] == k+'0')
                    dfs(i, j, k);
        bfs(k);
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        for (int u = 1; u <= 3; u++) for (int v = 1; v <= 3; v++)
        if (d[i][j][u] == 0 and d[i][j][v] == 0) e[u][v] = true;
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        if (t[i][j] != '#') {
            int dis = d[i][j][1];
            if (!e[1][2])              dis += d[i][j][2]-1, dis = min(dis, INF);
            if (!e[1][3] and !e[2][3]) dis += d[i][j][3]-1, dis = min(dis, INF);
            ans = min(ans, dis);
        }
    printf("%d\n", 2*ans > INF ? -1 : ans);
    return 0;
}
