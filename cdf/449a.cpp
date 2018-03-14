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

ll n, m, k;
ll a, b, c, d;

int main () {
    scanf("%lld%lld%lld", &n, &m, &k);
    if (k > n+m-2) return printf("-1\n"), 0;
    if (k < n and n % (k+1) == 0) return printf("%lld\n", m*n/(k+1)), 0;
    if (k < m and m % (k+1) == 0) return printf("%lld\n", n*m/(k+1)), 0;
    if (k < n) a = m*(n/(k+1));
    if (k < m) b = n*(m/(k+1));
    if (k >= n) c = m/(k-n+2);
    if (k >= m) d = n/(k-m+2);
    printf("%lld\n", max(max(a, b), max(c, d)));
    return 0;
}
