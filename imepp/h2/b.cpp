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

struct point {
    int x, y;
};

vector <point> pts;
point p;
int t, n;

int main () {
    scanf("%d", &t);
    while (t--) {
        pts.clear();
        scanf("%d", &n);
        while (n--) scanf("%d%d", &p.x, &p.y), pts.pb(p);
        sort(pts.begin(), pts.end(), [](point a, point b) {
             if (a.x == b.x) return a.y > b.y;
             return a.x < b.x;
             });
        for (auto z : pts) printf("%d %d\n", z.x, z.y);
    }
    return 0;
}
