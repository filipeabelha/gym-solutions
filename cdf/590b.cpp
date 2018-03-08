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
const int N = 1e5+5;

typedef long double type;

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }

struct point {
    type x, y;

    point() : x(0), y(0) {}
    point(type x, type y) : x(x), y(y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x+p.x, y+p.y); }
    point operator -(point p) { return point(x-p.x, y-p.y); }

    point operator *(type k) { return point(k*x, k*y); }
    point operator /(type k) { return point(x/k, y/k); }

    type operator *(point p) { return x*p.x + y*p.y; }
    type operator %(point p) { return x*p.y - y*p.x; }

    ld abs() { return sqrt(x*x + y*y); }
    type abs2() { return x*x + y*y; }
};

point u, w, a, b;
ld v, t;

int main () {
    scanf("%Lf%Lf", &u.x, &u.y);
    scanf("%Lf%Lf", &w.x, &w.y);
    scanf("%Lf%Lf", &v, &t);
    scanf("%Lf%Lf", &a.x, &a.y);
    scanf("%Lf%Lf", &b.x, &b.y);

    ld l = 0, x, r = 1000000000;
    while (abs(l-r) > EPS) {
        x = (l+r)/2;
        if (ge(x, t)) {
            point p = u + a*t + b*(x-t);
            if (ge((w-p).abs2()/(x*x), v*v)) l = x;
            else                             r = x;
        } else {
            point p = u + a*x;
            if (ge((w-p).abs2()/(x*x), v*v)) l = x;
            else                             r = x;
        }
    }

    printf("%.10Lf\n", x);
    return 0;
}
