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
const int N = 2e5+5, K = (1 << 8) + 5, L = 10;
const pii ZERO = {0, 0};

map <int, vi> l, r;
pii cur[L];
int dp[N][K], n, m, k, a, b;
vi u;

int main () {
    scanf("%d%d%d", &n, &m, &k);

    u.pb(0);
    u.pb(m+1);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        r[a].pb(b);
        l[b].pb(a);
        u.pb(a);
        u.pb(b);
    }

    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());

    for (int i = 0; i < u.size()-1; i++) {

        int nowInvalid = 0;
        for (int j = 0; j < k; j++)
            if (cur[j] == ZERO)
                nowInvalid |= (1 << j);

        int b = u[i];
        for (int a : l[b]) {
            pii p = {a, b};

            for (int j = 0; j < k; j++) {
                if (cur[j] == p) {
                    cur[j] = ZERO;
                    break;
                }
            }
        }

        int sameBits = 0;
        for (int j = 0; j < L; j++)
            if (cur[j] != ZERO)
                sameBits |= (1 << j);

        int a = u[i+1];
        for (int b : r[a]) {
            pii p = {a, b};

            for (int j = 0; j < k; j++) {
                if (cur[j] == ZERO) {
                    cur[j] = p;
                    break;
                }
            }
        }

        int nxtInvalid = 0;
        for (int j = 0; j < k; j++)
            if (cur[j] == ZERO)
                nxtInvalid |= (1 << j);

        for (int m = 0; m < (1 << k); m++) {
            if (m&nowInvalid) continue;
            int x = m&sameBits; // take only bits in common

            int cntm = __builtin_popcount(m);
            dp[i][m] += cntm&1;

            int cntx = __builtin_popcount(x);
            dp[i+1][x] = max(dp[i+1][x],
                dp[i][m] + (cntx&1)*(u[i+1]-u[i]-1));
        }

        for (int m = 0; m < (1 << k); m++) {
            if (m&nxtInvalid) continue;
            int x = m&sameBits; // take only bits in common

            dp[i+1][m] = dp[i+1][x];
        }
    }

    printf("%d\n", dp[u.size()-1][0]);

    return 0;
}
