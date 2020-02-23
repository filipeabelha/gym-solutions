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

ll n;

int main () {
    scanf("%lld", &n);

    vector <pll> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i].st);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i].nd);

    sort(a.begin(), a.end());

    set <ll> v;
    v.insert(a[0].st);

    for (int i = 1; i < n; i++) v.insert(max(*(v.rbegin())+1, a[i].st));

    for (int i = 0; i < n; i++) swap(a[i].st, a[i].nd);
    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = n-1; i >= 0; i--) {
        auto it = v.lower_bound(a[i].nd);
        int y = *it;

        ans += (y-a[i].nd)*a[i].st;
        v.erase(y);
    }

    printf("%lld\n", ans);

    return 0;
}
