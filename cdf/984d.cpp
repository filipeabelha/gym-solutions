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
const int N = 5e3+5;

ll n, t[N][N], mx[N][N], q, l, r;

int main () {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &t[1][i]);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            t[i][j] = t[i-1][j] ^ t[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            mx[i][j] = t[i][j];

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mx[i][j] = max(mx[i][j], max(mx[i-1][j], mx[i-1][j-1]));
        }
    }

    scanf("%lld", &q);
    while (q--) {
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", mx[r-l+1][r]);
    }
    return 0;
}
