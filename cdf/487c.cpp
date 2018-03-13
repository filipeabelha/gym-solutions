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

set <ll> p;
int cmp[N];

void primes () {
    for (int i = 2; i*i < N; i++) if (!cmp[i])
        for (int j = i*i; j < N; j += i) cmp[j] = 1;
    for (int i = 2; i < N; i++) if (!cmp[i]) p.insert(i);
}

ll fexp (ll b, ll e, ll m) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}

ll n;
ll a[N];

int main () {
    primes();
    scanf("%lld", &n);
    if (n == 1) return printf("YES\n1\n"), 0;
    if (n == 4) return printf("YES\n1\n3\n2\n4\n"), 0;
    if (!p.count(n)) return printf("NO\n"), 0;
    printf("YES\n");
    a[1] = 1;
    a[n] = n;
    ll x = 1;
    for (int i = 2; i < n; i++) {
        a[i] = (i*fexp(x, n-2, n)) % n;
        x *= a[i]; x %= n;
    }
    for (int i = 1; i <= n; i++) printf("%lld\n", a[i]);
    return 0;
}
