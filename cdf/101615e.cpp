#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
ld x, v, sum;

int main () {
    scanf("%d%Lf%Lf", &n, &x, &v);
    while (n--) {
        ld l, r, vy;
        scanf("%Lf%Lf%Lf", &l, &r, &vy);
        sum += vy*(l-r);
    }
    sum /= (ld) v*x;

    if (sum + EPS < -1 or sum - EPS > 1) {
        printf("Too hard\n");
        return 0;
    }

    ld t = asin(sum);
    ld ans = x/(v*cos(t));

    if (ans-EPS > 2.0*x/v) {
        printf("Too hard\n");
    }
    else printf("%.3Lf\n", ans);

    return 0;
}
