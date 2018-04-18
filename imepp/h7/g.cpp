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
const int N = 3e2+5;

int n, m, c, k, a, b, w, dist[N][N];

int main () {
    while (~scanf("%d%d%d%d", &n, &m, &c, &k) and (n or m or c or k)) {
        cl(dist, 63);
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &w);
            dist[a][b] = min(dist[a][b], w);
            dist[b][a] = min(dist[b][a], w);
        }

        for (int i = c-2; i >= 0; i--) {
            dist[i][c-1] = dist[i][i+1] + dist[i+1][c-1];
            for (int j = 0; j < n; j++) if (i != j and j != c-1)
                dist[i][j] = INF;
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

        printf("%d\n", dist[k][c-1]);


    }
    return 0;
}
