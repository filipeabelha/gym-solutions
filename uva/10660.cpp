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
const int N = 1e2+5;

ll tc, n, a, b, c, t[N][N], ans[N];

pll p (ll x) {return {x/5, x%5};}
ll dis (pll a, pll b) { return abs(a.st-b.st) + abs(a.nd-b.nd); }

int main () {
    scanf("%lld", &tc);
    while (tc--) {
        cl(t, 0);

        scanf("%lld", &n);
        while (n--) {
            scanf("%lld%lld%lld", &a, &b, &c);
            t[a][b] = c;
        }

        ans[0] = LINF;

        for (int i = 0; i < 25; i++)
        for (int j = i+1; j < 25; j++)
        for (int k = j+1; k < 25; k++)
        for (int l = k+1; l < 25; l++)
        for (int m = l+1; m < 25; m++) {
            ll sum = 0;
            for (int a = 0; a < 25; a++) {
                ll x = p(a).st;
                ll y = p(a).nd;
                ll w = t[x][y];
                ll d = LINF;
                d = min(d, w*dis(p(a), p(i)));
                d = min(d, w*dis(p(a), p(j)));
                d = min(d, w*dis(p(a), p(k)));
                d = min(d, w*dis(p(a), p(l)));
                d = min(d, w*dis(p(a), p(m)));
                sum += d;
            }
            if (ans[0] > sum) {
                ans[0] = sum;
                ans[1] = i;
                ans[2] = j;
                ans[3] = k;
                ans[4] = l;
                ans[5] = m;
            }
        }

        for (int i = 1; i <= 5; i++) printf("%lld%c", ans[i], " \n"[i==5]);

    }
    return 0;
}
