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
typedef pair<pll, ll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

ll n, a[N], bit[N], ans;

void add (ll p) {
    for (p+=2; p<N; p += p&-p) bit[p] += 1;
}

ll query (ll p) {
    ll r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

ll rangesum (ll a, ll b) {
    if (b < a) return 0;
    return query(b)-(a ? query(a-1) : 0);
}

vi ind[N];
pll qry[N];

int main () {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i] = min(a[i], n);
        ind[a[i]].pb(i);
        qry[i] = {i+1, a[i]};
    }

    for (int x = n; x >= 1; x--) {
        for (auto i : ind[x]) add(i);
        ans += rangesum(qry[x].st, qry[x].nd);
    }
    printf("%lld\n", ans);
    return 0;
}
