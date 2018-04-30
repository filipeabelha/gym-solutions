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

ll n, q, c, x, y, z, b[N][N][20];
ll t, xa, ya, xb, yb;

int main () {
    scanf("%lld%lld%lld", &n, &q, &c);
    while (n--) {
        scanf("%lld%lld%lld", &x, &y, &z);
        for (int i = 0; i <= c; i++)
            b[x][y][i] += (z+i) % (c+1);
    }

    for (int k = 0; k < 20; k++)
        for (int i = 1; i < N; i++)
            for (int j = 1; j < N; j++)
                b[i][j][k] += b[i-1][j][k] + b[i][j-1][k] - b[i-1][j-1][k];

    while (q--) {
        scanf("%lld%lld%lld%lld%lld", &t, &xa, &ya, &xb, &yb);
        t %= (c+1);
        printf("%lld\n", b[xb][yb][t] - b[xa-1][yb][t] - b[xb][ya-1][t] + b[xa-1][ya-1][t]);
    }
    return 0;
}
