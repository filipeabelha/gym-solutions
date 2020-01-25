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
const int INF = 1e9, MOD = 1e9+7;
const int N = 1e5+5;

ll n, m;
vector <pll> v;

bool ok (ll d) {
    ll dl = 0;
    ll dc = 0;
    for (auto p : v) {
        ll l = p.st;
        ll c = p.nd;
        if (l*d > c) {
            dl += l;
            dc += c;
        }
    }
    return (dl >= LLONG_MAX/d) or (dl*d-dc >= m);
}

int main () {
    scanf("%lld%lld", &n, &m);
    v.resize(n);

    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &v[i].st, &v[i].nd);

    ll l = 1, m, r = 2*INF;
    while (l < r) {
        m = (l+r)/2;
        if (!ok(m)) l = m+1;
        else r = m;
    }
    printf("%lld\n", l);


    return 0;
}
