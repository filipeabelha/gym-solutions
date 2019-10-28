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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

bool ge(ld x, ld y) { return x + EPS > y; }
bool le(ld x, ld y) { return x - EPS < y; }

ld a, d;
ll n;

int main () {
    scanf("%Lf%Lf%lld", &a, &d, &n);
    for (int i = 1; i <= n; i++) {
        ld len = i*d;
        len -= (4*a)*((ll) (len/(4*a)));
        if (ge(len, 0) and le(len, a)) {
            printf("%.10Lf %.10Lf\n", len, (ld) 0);
            continue;
        }
        len -= a;
        if (ge(len, 0) and le(len, a)) {
            printf("%.10Lf %.10Lf\n", a, len);
            continue;
        }
        len -= a;
        if (ge(len, 0) and le(len, a)) {
            printf("%.10Lf %.10Lf\n", a-len, a);
            continue;
        }
        len -= a;
        if (ge(len, 0) and le(len, a)) {
            printf("%.10Lf %.10Lf\n", (ld) 0, a-len);
            continue;
        }
    }

    return 0;
}
