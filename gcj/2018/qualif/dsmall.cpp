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

int tc;
ld l, th;

int main () {
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        printf("Case #%d:\n", t);
        scanf("%Lf", &l);
        th = asin(l*l-1)/2;
        ld s = 0.5*sin(th);
        ld c = 0.5*cos(th);
        printf("%.10Lf %.10Lf 0\n", s, c);
        printf("%.10Lf %.10Lf 0\n", c, -s);
        printf("0 0 0.5\n");
    }
    return 0;
}
