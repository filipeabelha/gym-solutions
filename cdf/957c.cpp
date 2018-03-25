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
const int N = 1e5+5;

int n, u, x;
vi v;
ld ans;

int main () {
    scanf("%d%d", &n, &u);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        v.pb(x);
    }
    for (int i = 0; i < n; i++) {
        int k = upper_bound(v.begin(), v.end(), v[i]+u) - v.begin() - 1;
        if (k != i) {
            ld num = v[k]-v[i+1];
            ld den = v[k]-v[i];
            ans = max(ans, num/den);
        }
    }
    if (ans == 0) return printf("-1\n"), 0;
    printf("%.10Lf\n", ans);
    return 0;
}
