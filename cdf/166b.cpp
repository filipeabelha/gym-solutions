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

    bool operator ==(point p) { return x == p.x and y == p.y; }
    bool operator !=(point p) { return x != p.x  or y != p.y; }
    bool operator <(const point p) const { return (x < p.x) or (x == p.x and y < p.y); }

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


point origin;
bool radial(point p, point q) {
    int dir = p.dir(origin, q);
    return dir > 0 or (!dir and p.on_seg(origin, q));
}

vector<point> convex_hull(vector<point> pts) {
    vector<point> ch(pts.size()+5);
    point mn = pts[0];

    for(point p : pts) if (p.y < mn.y or (p.y == mn.y and p.x < p.y)) mn = p;

    origin = mn;
    sort(pts.begin(), pts.end(), radial);

    int n = 0;

    for(point p : pts) {
        while (n > 1 and ch[n-1].dir(ch[n-2], p) < 0) n--;
        ch[n++] = p;
    }

    for(int i=pts.size()-1; i >=1; --i)
        if (pts[i] != ch[n-1] and !pts[i].dir(pts[0], ch[n-1]))
            ch[n++] = pts[i];

    ch.resize(n);
    return ch;
}

ll n, m;
vector <point> a, b, c;

int main () {
    scanf("%lld", &n);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
        c.pb(a[i]);
    }

    scanf("%lld", &m);
    b.resize(m);
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &b[i].x, &b[i].y);
        c.pb(b[i]);
    }

    c = convex_hull(c);
    sort(c.begin(), c.end());

    int ok = 1;
    for (auto p : b) if (binary_search(c.begin(), c.end(), p)) ok = 0;

    printf("%s\n", ok ? "YES" : "NO");

    return 0;
}
