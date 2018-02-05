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
const int N = 2e3+5;

int n, m, k, t[N][N], a[N][N], b[N][N], sz;
char lin[N];
ll ans;

int main () {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf(" %s", lin);
        sz = strlen(lin);
        for (int j = 1; j <= sz; j++)
            a[i][j] = b[i][j] = t[i][j] = (lin[j-1] == '.' ? 1 : 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] += a[i][j-1];
            b[i][j] += b[i-1][j];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = k; j <= m; j++)
            ans += ((a[i][j] - a[i][j-k]) == k);
    if (k > 1) for (int j = 1; j <= m; j++)
        for (int i = k; i <= n; i++)
            ans += ((b[i][j] - b[i-k][j]) == k);
    printf("%lld\n", ans);
    return 0;
}
