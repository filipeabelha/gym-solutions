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
#define _ << " " <<
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

    int dir(point o, point p) {
        type x = (*this - o) % (p - o);
        return ge(x,0) - le(x,0);
    }

    bool on_seg(point p, point q) {
        if (this->dir(p, q)) return 0;
        return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and
            ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
    }

};


int direction(point o, point p, point q) { return p.dir(o, q); }

bool segments_intersect(point p, point q, point a, point b) {
    int d1, d2, d3, d4;
    d1 = direction(p, q, a);
    d2 = direction(p, q, b);
    d3 = direction(a, b, p);
    d4 = direction(a, b, q);
    if (d1*d2 < 0 and d3*d4 < 0) return 1;
    return p.on_seg(a, b) or q.on_seg(a, b) or
        a.on_seg(p, q) or b.on_seg(p, q);
}

point lines_intersect(point p, point q, point a, point b) {
    point r = q-p, s = b-a, c(p%q, a%b);
    if (eq(r%s,0)) return point(INF, INF);
    return point(point(r.x, s.x) % c, point(r.y, s.y) % c) / (r%s);
}

vector <pii> v(4);

int main () {
    for (int i = 0; i < 4; i++) cin >> v[i].st >> v[i].nd;
    sort(v.begin(), v.end());

    do {
        point a = point(v[0].st, v[0].nd);
        point b = point(v[1].st, v[1].nd);
        point c = point(v[2].st, v[2].nd);
        point d = point(v[3].st, v[3].nd);
        if (!segments_intersect(a, b, c, d)) continue;
        point p = lines_intersect(a, b, c, d);
        cout << setprecision(10);
        cout << p.x _ p.y << endl;
        break;

    } while (next_permutation(v.begin(), v.end()));

    return 0;
}
