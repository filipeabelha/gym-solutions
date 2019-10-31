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
const int N = 1e5+5;

int bit[N];

void add (int p, int v) {
    for (p+=2; p<N; p += p&-p) bit[p] += v;
}

ll query (int p) {
    ll r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

int x, y, h, z, a, b, ans;
vector <pii> v;

int main () {
    scanf("%d%d%d%d", &x, &y, &h, &z);

    ll ans = ((ll) h+1)*((ll) z+1);

    for (int i = 0; i < h; i++) {
        pii p;
        scanf("%d%d", &p.nd, &p.st);
        v.pb(p);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        v[i].st = i+1;
        swap(v[i].st, v[i].nd);
    }

    sort(v.begin(), v.end());

    for (int i = v.size()-1; i >= 0; i--) {
        add(v[i].nd, 1);
        ans += query(v[i].nd-1);
    }

    cl(bit, 0);
    v.clear();

    for (int i = 0; i < z; i++) {
        pii p;
        scanf("%d%d", &p.nd, &p.st);
        v.pb(p);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        v[i].st = i+1;
        swap(v[i].st, v[i].nd);
    }

    sort(v.begin(), v.end());

    for (int i = v.size()-1; i >= 0; i--) {
        add(v[i].nd, 1);
        ans += query(v[i].nd-1);
    }

    printf("%lld\n", ans);

    return 0;
}
