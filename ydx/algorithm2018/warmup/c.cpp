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
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

typedef long double type;
typedef pair<type, type> T;

const type EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

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

    // o is the origin, p is another point
    // dir == +1 => p is clockwise from this
    // dir ==  0 => p is colinear with this
    // dir == -1 => p is counterclockwise from this
    int dir(point o, point p) {
        type x = (*this - o) % (p - o);
        return ge(x,0) - le(x,0);
    }
};


int direction(point o, point p, point q) { 
    //printf("(%.2Lf, %.2Lf) + (%.2Lf, %.2Lf) + (%.2Lf, %.2Lf) => %d\n",
    //       o.x, o.y, p.x, p.y, q.x, q.y, p.dir(o, q));
    return p.dir(o, q);
}

int n, op;
type r, xa, ya, xb, yb, xc, yc, xd, yd;
set <T> cnt;
vector <point> centers;

int main () {
    scanf("%d", &n);
    while (n--) {
        scanf(" %d", &op);
        if (op == 0) {
            scanf(" %Lf %Lf %Lf", &r, &xa, &ya);
            point p(xa, ya);
            if (!cnt.count(mp(p.x, p.y)))
                cnt.insert(mp(p.x, p.y)), centers.pb(p);
        }
        if (op == 1) {
            scanf(" %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd);
            type x = (xa + xb + xc + xd)/4;
            type y = (ya + yb + yc + yd)/4;
            point p(x, y);
            if (!cnt.count(mp(p.x, p.y)))
                cnt.insert(mp(p.x, p.y)), centers.pb(p);
        }
    }
    int ok = 1;
    for (int i = 2; i < centers.size(); i++)
        if (direction(centers[i], centers[0], centers[1]) != 0) ok = 0;
    printf("%s\n", ok ? "Yes" : "No");
    return 0;
}
