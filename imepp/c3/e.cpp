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

ll l, r;

int main () {
    scanf("%lld%lld", &l, &r);
    for (ll a = l; a <= r; a++) for (ll b = a+1; b <= r; b++)
        for (ll c = b+1; c <= r; c++)
            if (gcd(a, b) == 1 and
                gcd(b, c) == 1 and
                gcd(a, c) > 1)
                return printf("%lld %lld %lld\n", a, b, c), 0;
    printf("-1\n");
    return 0;
}
