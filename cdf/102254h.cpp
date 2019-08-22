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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

ll q, n, m;

int cmp[N];
vi pr;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j+=i) cmp[j]=1;
        pr.pb(i);
    }
}

ll phi (ll n) {
    ll ind = 0, ans = n;
    ll pf = pr[0];
    while (pf * pf <= n) {
        if (n % pf == 0) ans -= ans/pf;
        while (n % pf == 0) n /= pf;
        pf = pr[++ind];
    }
    if (n != 1) ans -= ans/n;
    return ans;
}

ll ph[N];

int main () {
    primes();
    for (int i = 1; i < N; i++) ph[i] = phi(i);
    scanf("%lld", &q);
    while (q--) {
        scanf("%lld%lld", &n, &m);
        if (gcd(n, m) != 1) printf("-1\n");
        else printf("%lld\n", phi(m));
    }
    return 0;
}
