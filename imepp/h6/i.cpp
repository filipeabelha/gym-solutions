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

ll t, n, m, d[N], numkeys, key;

int main () {
    scanf("%lld", &t);
    while (t--) {
        cl(d, 0);

        scanf("%lld%lld", &n, &m);
        for (ll i = 0; i < m; i++) {
            scanf("%lld", &numkeys);
            while (numkeys--) {
                scanf("%lld", &key);
                d[i] |= (1ll << key);
            }
        }

        int ans = INF;
        for (ll i = 0; i < (1ll << m); i++) {
            bitset <50> msk;
            int cnt = 0;
            for (ll j = 0; (1ll << j) <= i; j++) {
                if (i & (1ll << j)) {
                    msk |= d[j];
                    cnt++;
                }
            }
            if (msk.count() >= n) ans = min(ans, cnt);
        }
        if (ans != INF) printf("%d\n", ans);
        else printf("Desastre!\n");
    }
    return 0;
}
