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
const int N = 3e2+5;
const int M = 1e5+5;

int a, b, x, ans, lincnt, colcnt;
char t[N][N];
int vis[M], k[M], lin[N][N], col[N][N];
vi adj[M];

bool match(int u) {
    if (vis[u] == x) return 0;
    vis[u] = x;
    for (int v : adj[u])
        if (!k[v] or match(k[v])) return k[v] = u;
    return 0;
}

int tc;

int main () {
    scanf("%d", &tc);
    while (tc--) {

        memset(lin, 0, sizeof lin);
        memset(col, 0, sizeof col);
        memset(vis, 0, sizeof vis);
        memset(k, 0, sizeof k);
        for (int i = 0; i < M; i++) adj[i].clear();

        x = ans = 0;
        lincnt = colcnt = 1;

        scanf("%d%d", &a, &b);

        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++) {
                scanf(" %c", &t[i][j]);
            }

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (t[i][j] == 'A' and j != 1) lincnt++;
                lin[i][j] = lincnt;
            }
            lincnt++;
        }

        for (int j = 1; j <= b; j++) {
            for (int i = 1; i <= a; i++) {
                if (t[i][j] == 'A' and i != 1) colcnt++;
                col[i][j] = colcnt;
            }
            colcnt++;
        }

        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++) {
                if (t[i][j] == 'H') {
                    adj[lin[i][j]].pb(col[i][j]);
                }
            }

        for (int i = 0; i < M; i++) ++x, ans += match(i);

        printf("%d\n", ans);
    }

    return 0;
}
