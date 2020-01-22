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
typedef vector<ll> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+10;

int cmp[N];
vll pr;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j+=i) cmp[j]=1;
        pr.pb(i);
    }
}

int par[N], sz[N], cur;

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    cur--;
}

ll n, a, b, p;

int main () {
    primes();
    scanf("%lld", &n);
    for (int t = 1; t <= n; t++) {
        printf("Case #%d: ", t);
        for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
        scanf("%lld%lld%lld", &a, &b, &p);
        cur = b-a+1;

        for (auto x : pr) {
            if (x < p) continue;
            ll ini = x*((a-1)/x + 1);
            for (ll i = ini; i <= b; i += x) {
                unite(ini-a, i-a);
            }
        }

        printf("%d\n", cur);

    }

    return 0;
}
