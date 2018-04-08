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

ll pot[N], n;
ll x, d;

int main () {
    for (int i = 1; ; i++) {
        pot[i] = (1ll << i) - 1;
        if (pot[i] > 2*INF) break;
    }
    scanf("%lld%lld", &x, &d);
    int i = 30;
    vi v;
    while (x) {
        while (pot[i] > x) i--;
        x -= pot[i];
        n += i;
        v.pb(i);
    }

    if (n > 1e4) return printf("-1\n"), 0;
    printf("%lld\n", n);
    for (int j = 0; j < v.size(); j++) {
        int x = v[j];
        for (int i = 1; i <= x; i++) printf("%lld ", 1+(j*3*d));
    }
    printf("\n");
    return 0;
}
