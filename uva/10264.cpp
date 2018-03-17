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

int n;
ll w[N], p[N], ans;

int main () {
    while (~scanf("%d", &n)) {
        cl(w, 0);
        cl(p, 0);
        ans = 0;
        for (int i = 0; i < (1 << n); i++) scanf("%lld", &w[i]);
        for (int i = 0; i < (1 << n); i++) {
            for (int j = i+1; j < (1 << n); j++) {
                bitset <15> b(i^j);
                if (b.count() == 1) {
                    p[i] += w[j];
                    p[j] += w[i];
                }
            }
        }
        for (int i = 0; i < (1 << n); i++) {
            for (int j = i+1; j < (1 << n); j++) {
                bitset <15> b(i^j);
                if (b.count() == 1) {
                    ans = max(ans, p[i]+p[j]);
                }
            }
        }
        printf("%lld\n", ans);

    }
    return 0;
}
