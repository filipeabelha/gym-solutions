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

typedef long long type;

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

    bool on_seg(point p, point q) {
        if (this->dir(p, q)) return 0;
        return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and
            ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
    }

    ld abs() { return sqrt(x*x + y*y); }
    type abs2() { return x*x + y*y; }
    ld dist(point x) { return (*this - x).abs(); }
    type dist2(point x) { return (*this - x).abs2(); }

    ld arg() { return atan2l(y, x); }

    // Project point on vector y
    point project(point y) { return y * ((*this * y) / (y * y)); }

    // Project point on line generated by points x and y
    point project(point x, point y) { return x + (*this - x).project(y-x); }

    ld dist_line(point x, point y) { return dist(project(x, y)); }

    ld dist_seg(point x, point y) {
        return project(x, y).on_seg(x, y) ? dist_line(x, y) :  min(dist(x), dist(y));
    }

    point rotate(ld sin, ld cos) { return point(cos*x-sin*y, sin*x+cos*y); }
    point rotate(ld a) { return rotate(sin(a), cos(a)); }
    // rotate around the argument of vector p
    point rotate(point p) { return rotate(p.x / p.abs(), p.y / p.abs()); }
};


ld double_of_triangle_area(point p1, point p2, point p3) {
    return abs((p2-p1) % (p3-p1));
}

bool point_inside_triangle(point p, point p1, point p2, point p3) {
    ld a1, a2, a3, a;
    a =  double_of_triangle_area(p1, p2, p3);
    a1 = double_of_triangle_area(p, p2, p3);
    a2 = double_of_triangle_area(p, p1, p3);
    a3 = double_of_triangle_area(p, p1, p2);
    return eq(a, a1 + a2 + a3);
}

point a[10], b[10];

int main () {
    for (int i = 1; i <= 4; i++) scanf("%lld%lld", &a[i].x, &a[i].y);
    for (int i = 1; i <= 4; i++) scanf("%lld%lld", &b[i].x, &b[i].y);

    a[5].x = (a[1].x + a[2].x + a[3].x + a[4].x)/4;
    a[5].y = (a[1].y + a[2].y + a[3].y + a[4].y)/4;

    b[5].x = (b[1].x + b[2].x + b[3].x + b[4].x)/4;
    b[5].y = (b[1].y + b[2].y + b[3].y + b[4].y)/4;

    bool ans = false;
    for (int i = 1; i <= 5; i++) {
        if (point_inside_triangle(a[i], b[1], b[2], b[3])) ans = true;
        if (point_inside_triangle(a[i], b[1], b[2], b[4])) ans = true;
        if (point_inside_triangle(a[i], b[1], b[3], b[4])) ans = true;
        if (point_inside_triangle(a[i], b[2], b[3], b[4])) ans = true;

        if (point_inside_triangle(b[i], a[1], a[2], a[3])) ans = true;
        if (point_inside_triangle(b[i], a[1], a[2], a[4])) ans = true;
        if (point_inside_triangle(b[i], a[1], a[3], a[4])) ans = true;
        if (point_inside_triangle(b[i], a[2], a[3], a[4])) ans = true;
    }


    printf("%s\n", ans ? "YES" : "NO");
    return 0;
}
