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
const int N = 4e4+5;

ll t, x;

int main () {
    scanf("%lld", &t);

    while (t--) {
        scanf("%lld", &x);
        int ok = 0;
        for (ll n = 1; n < N; n++) {
            if (n*n - x < 0) continue;
            ll z = (sqrt(n*n-x)+EPS);
            if (z > 0) {
                ll k = n/z;
                if ((n/k)*(n/k) == n*n - x) {
                    printf("%lld %lld\n", n, k);
                    ok = 1;
                    break;
                }
            }
        }
        if (!ok) printf("-1\n");
    }

    return 0;
}
