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

const ld EPS = 1e-16, EPS2 = 1e-10, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

bool ge(ld x, ld y) { return x + EPS2 > y; }
bool le(ld x, ld y) { return x - EPS2 < y; }
bool eq(ld x, ld y) { return ge(x, y) and le(x, y); }

ld acc[N][2];
ll n[2];
ll x[N][2], y[N][2];
ll dx[N][2], dy[N][2];

ld sqrt (ll x) {
    ld l = 0, m, r = INF;
    while (abs(l-r) > EPS) {
        m = (l+r)/2;
        if (m*m + EPS > x) r = m;
        else l = m;
    }

    return l;
}

ld dist (ld xa, ld ya, ld xb = 0, ld yb = 0) {
    return sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
}

int main () {
    for (int k = 0; k < 2; k++) {
        scanf("%lld", &n[k]);
        for (int i = 0; i < n[k]; i++) {
            scanf("%lld%lld", &x[i][k], &y[i][k]);
            if (i > 0) {
                acc[i][k] = acc[i-1][k] + dist(x[i][k], y[i][k], x[i-1][k], y[i-1][k]);
                dx[i-1][k] = x[i][k]-x[i-1][k];
                dy[i-1][k] = y[i][k]-y[i-1][k];
            }
        }
    }

    ld ans = dist(x[0][0], y[0][0], x[0][1], y[0][1]);
    for (int k = 0; k < 2; k++) {
        int j = 0;
        for (int i = 0; i < n[k]-1; i++) {
            while (j+1 < n[k^1]-1 and le(acc[j+1][k^1], acc[i][k])) {
                j++;
            }

            if (!le(acc[j][k^1], acc[i][k])) continue;
            if (ge(acc[i][k], acc[j][k^1] + dist(dx[j][k^1], dy[j][k^1]))) continue;
            ld dist1 = acc[i][k] + dist(dx[i][k], dy[i][k]);
            ld dist2 = acc[j][k^1] + dist(dx[j][k^1], dy[j][k^1]);

            // both paths have no segment switch between the interval
            // [mn, mx] of accumulated distances
            ld mn = max(acc[i][k], acc[j][k^1]);
            ld mx = min(dist1, dist2);

            // famn is a number between [0, 1] which says the fraction
            // of the interval A where mn is in. Same for mx
            ld famn = (mn-acc[i][k])/dist(dx[i][k], dy[i][k]);
            ld famx = (mx-acc[i][k])/dist(dx[i][k], dy[i][k]);

            ld fbmn = (mn-acc[j][k^1])/dist(dx[j][k^1], dy[j][k^1]);
            ld fbmx = (mx-acc[j][k^1])/dist(dx[j][k^1], dy[j][k^1]);

            // cur is the exact coordinate where mn lies
            ld curxa = x[i][k] + famn*dx[i][k];
            ld curya = y[i][k] + famn*dy[i][k];

            ld curxb = x[j][k^1] + fbmn*dx[j][k^1];
            ld curyb = y[j][k^1] + fbmn*dy[j][k^1];

            // end is the exact coordinate where mx lies
            ld endxa = x[i][k] + famx*dx[i][k];
            ld endya = y[i][k] + famx*dy[i][k];

            ld endxb = x[j][k^1] + fbmx*dx[j][k^1];
            ld endyb = y[j][k^1] + fbmx*dy[j][k^1];

            ld dxa = endxa - curxa;
            ld dya = endya - curya;

            ld dxb = endxb - curxb;
            ld dyb = endyb - curyb;

            ld d = dist(dxa, dya, dxb, dyb);
            if (eq(d, 0)) {
                ans = min(ans, dist(curxa, curya, curxb, curyb));
            } else {
                ld tmin = -((curxa-curxb)*(dxa-dxb) + (curya-curyb)*(dya-dyb))/(d*d);
                tmin = min(tmin, (ld) 1);
                tmin = max(tmin, (ld) 0);
                ld newxa = curxa + tmin*dxa;
                ld newya = curya + tmin*dya;

                ld newxb = curxb + tmin*dxb;
                ld newyb = curyb + tmin*dyb;

                ans = min(ans, dist(newxa, newya, newxb, newyb));
            }
        }
    }
    printf("%.9Lf\n", ans);
    return 0;
}
