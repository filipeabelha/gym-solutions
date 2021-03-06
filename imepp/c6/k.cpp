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
const int N = 5e2+5;

ll n, dist[N][N], v[N], ans[N];

int main () {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lld", &dist[i][j]);

    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);

    for (int z = n; z >= 1; z--) {
        ll k = v[z];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        for (int i = z; i <= n; i++)
            for (int j = z; j <= n; j++)
                ans[z] += dist[v[i]][v[j]];
    }

    for (int i = 1; i <= n; i++) printf("%lld%c", ans[i], " \n"[i==n]);

    return 0;
}
