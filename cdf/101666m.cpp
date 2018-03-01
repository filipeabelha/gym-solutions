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

struct pt {
    ll x, y;
};

pt a, b, c;
ll n;
vector <pt> p;

int main () {
    scanf("%lld", &n);
    scanf("%lld%lld%lld%lld", &a.x, &a.y, &b.x, &b.y);
    if (a.x > b.x) swap(a, b);

    while (n--) {
        scanf("%lld%lld", &c.x, &c.y);
        if (c.x > max(a.x, b.x)) continue;
        if (c.y > max(a.y, b.y)) continue;
        if (c.x < min(a.x, b.x)) continue;
        if (c.y < min(a.y, b.y)) continue;
        p.pb(c);
    }

    sort(p.begin(), p.end(), [](pt u, pt v) {
         if (u.x == v.x and a.y <= b.y) return u.y < v.y;
         if (u.x == v.x and a.y > b.y)  return u.y > v.y;
         return u.x < v.x;
         });

    vector <ll> lis;

    for (auto z : p) {
        ll e;
        if (a.y <= b.y) e = z.y;
        else            e = -z.y;

        if (lis.empty() or e >= lis.back()) lis.pb(e);
        else {
            int pos = upper_bound(lis.begin(), lis.end(), e) - lis.begin();
            lis[pos] = e;
        }
    }

    ll ans = lis.size();
    printf("%lld\n", ans);

    return 0;
}
