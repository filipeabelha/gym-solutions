#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+50;

char c[N][N];
int n, m, vis[N][N], ans;

int main () {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %c", &c[i][j]);
        }
    }

    queue <pii> q;

    for (int x = 1; x < N; x++) {
        for (int y = 1; y < N; y++) {
            if (!vis[x][y]) {
                vis[x][y] = 1;
                q.push({x, y});
                ans++;

                while (q.size()) {
                    pii p = q.front(); q.pop();
                    int i = p.st;
                    int j = p.nd;
                    if (i > 0 and j < N-1 and c[i-1][j] != 92 and !vis[i-1][j+1]) {
                        vis[i-1][j+1] = 1;
                        q.push({i-1, j+1});
                    }

                    if (j > 0 and i < N-1 and c[i][j-1] != 92 and !vis[i+1][j-1]) {
                        vis[i+1][j-1] = 1;
                        q.push({i+1, j-1});
                    }

                    if (i > 0 and j > 0 and c[i-1][j-1] != 47 and !vis[i-1][j-1]) {
                        vis[i-1][j-1] = 1;
                        q.push({i-1, j-1});
                    }

                    if (i < N-1 and j < N-1 and c[i][j] != 47 and !vis[i+1][j+1]) {
                        vis[i+1][j+1] = 1;
                        q.push({i+1, j+1});
                    }
                }
            }
        }
    }

    printf("%d\n", ans-2);


    return 0;
}
