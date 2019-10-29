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

vector <plll> v;
int ans;

bool ok (ll xg, ll yg) {
    int ans = 0;
    for (auto p : v) {
        ll xr = p.nd.st;
        ll yr = p.nd.nd;
        ll r = p.st;
        ll dx = xr-xg;
        ll dy = yr-yg;
        if (dx*dx + dy*dy <= r*r) ans = 1;
    }
    return !ans;
}

int main () {
    ll xa, ya, xb, yb;
    scanf("%lld%lld%lld%lld", &xa, &ya, &xb, &yb);

    ll xmin, xmax, ymin, ymax;
    xmin = min(xa, xb);
    xmax = max(xa, xb);
    ymin = min(ya, yb);
    ymax = max(ya, yb);

    ll n;
    scanf("%lld", &n);
    while (n--) {
        ll x, y, r;
        scanf("%lld%lld%lld", &x, &y, &r);
        v.pb({r, {x, y}});
    }

    for (ll xg = xmin; xg <= xmax; xg++) ans += ok(xg, ymin);
    for (ll xg = xmin; xg <= xmax; xg++) ans += ok(xg, ymax);
    for (ll yg = ymin+1; yg <= ymax-1; yg++) ans += ok(xmin, yg);
    for (ll yg = ymin+1; yg <= ymax-1; yg++) ans += ok(xmax, yg);

    printf("%d\n", ans);


    return 0;
}
