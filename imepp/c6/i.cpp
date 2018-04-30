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

ll n, bit[N], ans[N];

void add (ll p) {
    for (p+=2; p<N; p += p&-p) bit[p]++;
}

ll query (ll p) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

map <int, vi> ind;

int main () {
    scanf("%lld", &n);
    vi v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        ind[v[i]].pb(i);
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    ll sz = n;
    ll acc = 0;
    for (int i = 0; i < v.size(); i++) {
        acc += sz*(v[i]-1-(i ? v[i-1] : 0));
        for (auto j : ind[v[i]]) ans[j] = acc + j - query(j) + 1;
        for (auto j : ind[v[i]]) add(j);
        acc += sz;
        sz -= ind[v[i]].size();
    }
    for (int i = 0; i < n; i++) printf("%lld\n", ans[i]);
    return 0;
}
