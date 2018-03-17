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
const int N = 1e6;

bitset <2*N+5> b;
int n, m, l, r, d;

int main () {
    while (~scanf("%d%d", &n, &m) and (n or m)) {
        b.reset();

        int ok = 1;

        while (n--) {
            scanf("%d%d", &l, &r);
            for (int i = 2*l+1; i <= 2*r; i++) {
                if (b.test(i)) ok = 0;
                b.set(i);
            }
        }

        while (m--) {
            scanf("%d%d%d", &l, &r, &d);
            while (1) {
                for (int i = 2*l+1; i <= min(2*r, 2*N); i++) {
                    if (b.test(i)) ok = 0;
                    b.set(i);
                }
                l += d;
                r += d;
                if (l > N) break;
            }
        }

        printf("%sCONFLICT\n", ok ? "NO " : "");
    }
    return 0;
}
