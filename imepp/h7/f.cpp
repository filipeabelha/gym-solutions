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
const int N = 2e2+5;

ll dist[N][N], n, e, t, m, a, b, w;

int main () {
    while (~scanf("%lld%lld", &n, &m) and n) {
        cl(dist, 63);
        for (int i = 1; i <= n; i++) dist[i][i] = 0;

        while (m--) {
            scanf("%lld%lld%lld", &a, &b, &w);
            dist[a][b] = min(dist[a][b], w);
        }

        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

        scanf("%lld%lld", &a, &b);
        printf("%lld\n", dist[a][b] == LINF ? -1 : dist[a][b]);
    }
    return 0;
}
