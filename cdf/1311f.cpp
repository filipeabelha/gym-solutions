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
const int N = 2e5+5;

ll bit[N];

void add (ll p, ll v) {
    for (p+=2; p<N; p += p&-p) bit[p] += v;
}

ll query (ll p) {
    ll r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

map <int, int> id;
int cnt;

ll n;
vector <pll> v;

int main () {
    scanf("%lld", &n);
    v.resize(n);
    for (int i = 0; i < n; i++) scanf("%lld", &v[i].nd);
    for (int i = 0; i < n; i++) scanf("%lld", &v[i].st);

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (!id[v[i].st]) id[v[i].st] = ++cnt;
        v[i].st = id[v[i].st];
        swap(v[i].st, v[i].nd);
    }

    sort(v.begin(), v.end());

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        pll p = v[i];
        ll pos = v[i].st;
        ll vel = v[i].nd;
        ans += pos*query(vel);
        add(vel, 1);
    }

    cl(bit, 0);

    for (int i = n-1; i >= 0; i--) {
        pll p = v[i];
        ll pos = v[i].st;
        ll vel = v[i].nd;
        ans -= pos*(query(N-1) - query(vel-1));
        add(vel, 1);
    }

    printf("%lld\n", ans);

    return 0;
}
