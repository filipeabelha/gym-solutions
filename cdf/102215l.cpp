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

const ld EPS = 1e-11, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ld xa, ya, ra;
ld xb, yb, rb;
ld xc, yc, rc;

ld square (ld n) {
    ld l = 0, m, r = INF;
    while (abs(l-r) > EPS) {
        m = (l+r)/2;
        if (m*m + EPS < n) l = m;
        else r = m;
    }
    return l;
}

int main () {
    scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &xa, &ya, &ra, &xb, &yb, &rb);
    ld dx = xb-xa;
    ld dy = yb-ya;
    rc = (ra + rb - square(dx*dx + dy*dy))/2.;
    xc = xa + (ra-rc)*dx/(ra+rb-2*rc);
    yc = ya + (ra-rc)*dy/(ra+rb-2*rc);

    printf("%.11Lf %.11Lf %.11Lf\n", xc, yc, rc);

    return 0;
}
