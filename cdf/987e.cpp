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
const int N = 1e6+5;

ll n, v[N], vis[N];

ll go (int x, int s) {
    vis[x] = 1;
    ll r = 1;
    if (v[x] != s) r += go(v[x], s);
    return r;
}

int main () {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);

    ll ans = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        ans += go(v[i], v[i]) - 1;
    }

    if (n&1) printf("%s\n", (ans&1) ? "Petr" : "Um_nik");
    else     printf("%s\n", (ans&1) ? "Um_nik" : "Petr");

    return 0;
}
