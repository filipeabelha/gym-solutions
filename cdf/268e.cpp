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
const int N = 5e4+5;

struct song {ll t, p;};

song s[N];
int n;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld%lld", &s[i].t, &s[i].p);

    sort(s, s+n, [](song a, song b) {
        return a.t*a.p*(100-b.p) > b.t*b.p*(100-a.p);
         });

    ld sum = 0;
    ld ans = 0;
    for (int i = 0; i < n; i++) {
        ans += s[i].t + sum*(1-s[i].p/100.);
        sum += s[i].t*s[i].p/100.;
    }
    printf("%.10Lf\n", ans);
    return 0;
}
