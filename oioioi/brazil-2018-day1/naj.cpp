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

typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 6e2+5;
const int M = 1e4+5;

typedef long long type;

const type LINF = 0x3f3f3f3f3f3f3f3f;

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }

struct point {
    type x, y, c;

    point() : x(0), y(0) {}
    point(type x, type y) : x(x), y(y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x+p.x, y+p.y); }
    point operator -(point p) { return point(x-p.x, y-p.y); }

    point operator *(type k) { return point(k*x, k*y); }
    point operator /(type k) { return point(x/k, y/k); }

    type operator *(point p) { return x*p.x + y*p.y; }
    type operator %(point p) { return x*p.y - y*p.x; }
};

point origin;
bool radial(point p, point q) {
    return ((p - origin) % (q - origin)) < 0;
}

int n, m;
type ans = -LINF, tot, sum[N][N];
point u[N], v[M];

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld%lld", &u[i].x, &u[i].y);

    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%lld%lld%lld", &v[i].x, &v[i].y, &v[i].c), tot += v[i].c;

    for (int i = 0; i < n; i++) {
        origin = u[i];
        sort(v, v+m, radial);

        int k = 0;
        while (k < m and v[k].x == u[i].x and v[k].y == u[i].y) k++;

        type cnt = 0;
        for (int j = i+1; j < i+n; j++) {
            while (k < m and ((u[j%n] - u[i]) % (v[k] - u[i])) > 0) {
                cnt += v[k].c;
                k++;
            }
            sum[i][j%n] = cnt;
        }
    }

    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) for (int k = j+1; k < n; k++)
        ans = max(ans, tot-sum[i][j]-sum[j][k]-sum[k][i]);

    printf("%lld\n", ans);

    return 0;
}
