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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e2+5;

ll dist[N][N];
vector <plll> v;
ll x, y, r;

bool reachable (int i, int j) {
    ll r = v[i].st;
    ll xa = v[i].nd.st;
    ll ya = v[i].nd.nd;

    ll xb = v[j].nd.st;
    ll yb = v[j].nd.nd;

    return (xb-xa)*(xb-xa) + (yb-ya)*(yb-ya) <= r*r;
}

ll manhattan (ll xa, ll ya, ll xb, ll yb) {
    return abs(xa-xb) + abs(ya-yb);
}

ll manhattan2 (int i, int j) {
    ll xa = v[i].nd.st;
    ll ya = v[i].nd.nd;

    ll xb = v[j].nd.st;
    ll yb = v[j].nd.nd;
    return abs(xa-xb) + abs(ya-yb);
}

int t, n;

int main () {
    scanf("%d", &t);
    while (t--) {
        cl(dist, 63);
        v.clear();
        v.pb({0, {0, 0}});
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld%lld%lld", &x, &y, &r);
            v.pb({r, {x, y}});
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) if (i != j) {
                if (reachable(i, j)) dist[i][j] = min(dist[i][j], 1ll*2);
                dist[i][j] = min(dist[i][j], manhattan2(i, j));
            }
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        ll xf, yf, xe, ye;
        scanf("%lld%lld%lld%lld", &xf, &yf, &xe, &ye);

        ll ans = manhattan(xf, yf, xe, ye);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ll xa = v[i].nd.st;
                ll ya = v[i].nd.nd;

                ll xb = v[j].nd.st;
                ll yb = v[j].nd.nd;

                ans = min(ans, manhattan(xf, yf, xa, ya) +
                          dist[i][j] +
                          manhattan(xb, yb, xe, ye));
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}
