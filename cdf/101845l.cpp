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
const int N = 3e3+5;

int n, a, b;
char ans[N][N];
vector <piii> v[N];
int dx[] = {+1, -1, +0, +0};
int dy[] = {+0, +0, +1, -1};

void solve (int l, int xa, int ya, int xb, int yb) {
    if (l < 2) return;
    bool up = false;
    bool left = false;
    int xm = (xa+xb)/2;
    int ym = (ya+yb)/2;
    if (a <= xm) up = true;
    if (b <= ym) left = true;
    if (left  and  up) v[l].pb({4, {xb, yb}}), solve(l/2, xa,   ya,   xm, ym);
    if (!left and  up) v[l].pb({3, {xb, ya}}), solve(l/2, xa,   ym+1, xm, yb);
    if (left  and !up) v[l].pb({2, {xa, yb}}), solve(l/2, xm+1, ya,   xb, ym);
    if (!left and !up) v[l].pb({1, {xa, ya}}), solve(l/2, xm+1, ym+1, xb, yb);
}

void insertPts (vector <pii> pts) {
    vector <pii> neighbors;
    for (auto p : pts)
        for (int i = 0; i < 4; i++)
            neighbors.pb({p.st+dx[i], p.nd+dy[i]});

    for (int i = 0; i < 26; i++) {
        int ok = 1;
        for (auto p : neighbors) {
            int x = p.st;
            int y = p.nd;
            if (ans[x][y] == i+'A') ok = 0;
        }
        if (ok) {
            for (auto p : pts) {
                int x = p.st;
                int y = p.nd;
                ans[x][y] = i+'A';
            }
            break;
        }
    }
}

int main () {
    scanf("%d%d%d", &n, &a, &b);
    ans[a][b] = '.';
    solve(n, 1, 1, n, n);

    for (int l = N-1; l > 2; l--) for (auto p : v[l]) {
        int t = p.st;
        int x = p.nd.st;
        int y = p.nd.nd;
        int d = l-1;
        int h = l/4;

        if (t == 1) {
            v[l/2].pb({1, {x,   y}});
            v[l/2].pb({1, {x+h, y+h}});
            v[l/2].pb({2, {x,   y+d}});
            v[l/2].pb({3, {x+d, y}});
        }
        if (t == 2) {
            v[l/2].pb({2, {x,   y}});
            v[l/2].pb({2, {x+h, y-h}});
            v[l/2].pb({1, {x,   y-d}});
            v[l/2].pb({4, {x+d, y}});
        }
        if (t == 3) {
            v[l/2].pb({3, {x,   y}});
            v[l/2].pb({3, {x-h, y+h}});
            v[l/2].pb({1, {x-d, y}});
            v[l/2].pb({4, {x,   y+d}});
        }
        if (t == 4) {
            v[l/2].pb({4, {x,   y}});
            v[l/2].pb({4, {x-h, y-h}});
            v[l/2].pb({2, {x-d, y}});
            v[l/2].pb({3, {x,   y-d}});
        }
    }

    for (auto p : v[2]) {
        int t = p.st;
        int x = p.nd.st;
        int y = p.nd.nd;

        vector <pii> pts;

        if (t == 1) {
            pts.pb({x,   y});
            pts.pb({x+1, y});
            pts.pb({x,   y+1});
        }
        if (t == 2) {
            pts.pb({x,   y});
            pts.pb({x+1, y});
            pts.pb({x,   y-1});
        }
        if (t == 3) {
            pts.pb({x,   y});
            pts.pb({x-1, y});
            pts.pb({x,   y+1});
        }
        if (t == 4) {
            pts.pb({x,   y});
            pts.pb({x-1, y});
            pts.pb({x,   y-1});
        }
        insertPts(pts);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c", ans[i][j] >= 'A' ? ans[i][j] : '.');
        }
        printf("\n");
    }

    return 0;
}
