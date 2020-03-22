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
const int N = 1e5+5;

ll n, c1, n1, c2, n2, x, y, d, dx, dy;

void extgcd(ll a, ll b, ll &x, ll &y, ll &d) {
    if (b) extgcd(b, a%b, y, x, d), y -= x*(a/b);
    else x = 1, y = 0, d = a;
}

int main () {
    while (~scanf("%lld", &n) and n) {
        scanf("%lld%lld%lld%lld", &c1, &n1, &c2, &n2);
        if (n % gcd(n1, n2) != 0) {
            printf("failed\n");
            continue;
        }

        x = y = d = 0;
        extgcd(n1, n2, x, y, d);

        x *= n/d;
        y *= n/d;

        dx = n2/gcd(n1, n2);
        dy = n1/gcd(n1, n2);

        if (c1*dx < c2*dy) {
            ll k = y/dy;
            if (k < 0 and abs(y) % abs(dy) != 0) k--;
            y -= k*dy;
            x += k*dx;
            if (x < 0) {
                printf("failed\n");
                continue;
            }
        } else {
            ll k = x/dx;
            if (k < 0 and abs(x) % abs(dx) != 0) k--;
            x -= k*dx;
            y += k*dy;
            if (y < 0) {
                printf("failed\n");
                continue;
            }
        }

        printf("%lld %lld\n", x, y);

    }

    return 0;
}
