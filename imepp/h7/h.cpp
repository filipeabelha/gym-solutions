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
const int N = 1e2+5;

int x, y, z, t, dist[N][N];

int main () {
    while (~scanf("%d", &x) and ++t) {
        printf("Test Set #%d\n", t);

        cl(dist, 63);

        for (int i = 1; i <= 20; i++) dist[i][i] = 0;

        while (x--) {
            scanf("%d", &y);
            dist[y][1] = dist[1][y] = 1;
        }

        for (int i = 2; i <= 19; i++) {
            scanf("%d", &x);
            while (x--) {
                scanf("%d", &y);
                dist[y][i] = dist[i][y] = 1;
            }
        }

        for (int k = 1; k <= 20; k++)
            for (int i = 1; i <= 20; i++)
                for (int j = 1; j <= 20; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

        scanf("%d", &x);
        while (x--) {
            scanf("%d%d", &y, &z);
            printf("%2d to %2d: %d\n", y, z, dist[y][z]);
        }
        printf("\n");
    }
    return 0;
}
