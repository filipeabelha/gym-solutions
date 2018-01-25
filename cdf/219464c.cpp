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
const int N = 1e3+5;

int m, n, x, t[N][N], cnt, ans;
vi v;

int main () {
    scanf("%d%d", &m, &n);
    if (n > m) swap(n, m);
    for (int i = 0; i < n*m; i++) {
        scanf("%d", &x);
        v.pb(x);
        ans += 4*x;
    }
    sort(v.begin(), v.end(), [](int a, int b) {return a > b;});
    t[1][1] = v[cnt++];
    for (int k = 2; k <= n; k++) {
        for (int i = 1; i < k; i++) t[i][k] = v[cnt++];
        for (int j = 1; j <= k; j++) t[k][j] = v[cnt++];
    }
    for (int j = n+1; j <= m; j++) for (int i = 1; i <= n; i++) t[i][j] = v[cnt++];
    for (int i = 1; i < n; i++) for (int j = 1; j <= m; j++) ans -= 2*min(t[i][j], t[i+1][j]);
    for (int j = 1; j < m; j++) for (int i = 1; i <= n; i++) ans -= 2*min(t[i][j], t[i][j+1]);
    printf("%d\n", ans);
    return 0;
}
