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
const int N = 1e3+10;

ll n, p, q, b;

int main () {
    scanf("%lld", &n);
    while (n--) {
        scanf("%lld%lld%lld", &p, &q, &b);
        q /= gcd(p, q);

        while (b > 1 and q > 1) {
            if (q % b == 0) q /= b;
            else b = gcd(q, b);
        }

        printf("%s\n", q == 1 ? "Finite" : "Infinite");
    }
    return 0;
}
