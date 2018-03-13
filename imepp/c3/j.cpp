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

int n, m;
ll a[N], b[N], c[N];

bool slv (int x) {
    for (int i = 1; i <= m; i++) c[i] = b[i];

    vector <pii> v;
    set <int> d;

    for (int i = x; i >= 1; i--) {
        if (a[i] and !d.count(a[i])) {
            d.insert(a[i]);
            v.pb({i, a[i]});
        }
    }
    if (d.size() != m) return false;

    for (int i = 1; i <= x; i++) {
        int j = v.back().st;
        int k = v.back().nd;
        if (i == j) return false;
        c[k]--;
        if (!c[k]) {
            v.pop_back();
            if (v.empty()) return true;
            c[v.back().nd]++;
        }
    }
    return false;
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
    int l = 0, mid, r = n;
    while (l < r) {
        mid = (l+r)/2;
        if (!slv(mid)) l = mid+1;
        else           r = mid;
    }
    printf("%d\n", slv(l) ? l : -1);
    return 0;
}
