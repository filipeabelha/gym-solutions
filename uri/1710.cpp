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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 5e2+10;

map <vi, int> sum;

int ans, n, m, x, y, z, a[N], b[N], c[N], d[N];

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    for (int p = 1; p <= m; p++) {
        vi region;
        scanf("%d%d%d", &x, &y, &z);
        for (int i = 1; i <= n; i++)
            if (x*a[i]+y*b[i]+z*c[i] > d[i]) region.pb(i);
        sum[region]++;
        ans = max(ans, sum[region]);
    }
    printf("%d\n", ans);
    return 0;
}
