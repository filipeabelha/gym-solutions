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
typedef pair <pii, int> T;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int n, m, t, vis[N][N];
int a, b, c, d, e, f;
queue <T> q;

bool chk (int i, int j) {
    if (vis[i][j] == 1) {
        if (i == 1 or i == n or j == 1 or j == m)
            return true;
    }
    return false;
}

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

int main () {
    scanf("%d%d%d", &n, &m, &t);
    while (t--) {
        cl(vis, 0);
        scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
        q.push({{c, d}, 2});
        q.push({{e, f}, 2});
        q.push({{a, b}, 1});

        vis[c][d] = vis[e][f] = 2;
        vis[a][b] = 1;

        int ok = 0;
        if (chk(a, b)) ok = 1;

        while (q.size()) {
            pii p = q.front().st;
            int v = q.front().nd; q.pop();
            int i = p.st;
            int j = p.nd;

            for (int k = 0; k < 4; k++) {
                int x = p.st + dx[k];
                int y = p.nd + dy[k];
                if (x < 1 or x > n) continue;
                if (y < 1 or y > m) continue;
                if (vis[x][y] >= v) continue;
                vis[x][y] = v;
                if (chk(x, y)) ok = 1;
                q.push({{x, y}, v});
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
