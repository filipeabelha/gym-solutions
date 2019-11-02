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

ll t, n, s;
vector <pll> v, a, b;

bool ok (ll med) {
    a.clear();
    b.clear();
    for (auto p : v) {
        if (p.nd >= med) b.pb(p);
        else a.pb(p);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (b.size() < n/2+1) return false;
    /*printf("==== M = %lld | S = %lld ====\n", med, s);
    if (a.size()) printf("==== A ====\n");
    for (auto p : a) db(p.st _ p.nd);
    if (b.size()) printf("==== B ====\n");
    for (auto p : b) db(p.st _ p.nd);*/
    ll tot = 0;
    for (int i = 0; i < n/2+1; i++) {
        tot += max(med, b.back().st);
        b.pop_back();
    }
    for (auto p : b) tot += p.st;
    for (auto p : a) tot += p.st;
    //printf("==== TOTAL: %lld ====\n", tot);
    //printf("******************\n");
    return tot <= s;
}

int main () {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &s);
        v.clear();
        v.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld", &v[i].st, &v[i].nd);
        }
        ll l = 0, m, r = LINF;
        while (l < r) {
            m = (l+r+1)/2;
            if (!ok(m)) r = m-1;
            else l = m;
        }
        printf("%lld\n", l);

    }

    return 0;
}
