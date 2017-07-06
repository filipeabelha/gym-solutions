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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
vi u, v;

int chk (int m) {
    vi uu, vv;
    for (int i = 0; i < n; i++) if (u[i] > m) uu.pb(u[i]);
    for (int i = 0; i < n; i++) if (v[i] > m) vv.pb(v[i]);
    if (uu.size()&1 or vv.size()&1) return 0;
    for (int i = 1; i < uu.size(); i+=2) if (uu[i] != uu[i-1]) return 0;
    for (int i = 1; i < vv.size(); i+=2) if (vv[i] != vv[i-1]) return 0;
    return 1;
}

int main () {
    while(~scanf("%d", &n)) {
        u.clear();
        v.clear();
        for (int x, i = 0; i < n; i++) scanf("%d", &x), u.pb(x);
        for (int x, i = 0; i < n; i++) scanf("%d", &x), v.pb(x);
        int l, m, r;
        l = 0, r = 1e9;
        while (l < r) {
            m = (l+r)/2;
            if (!chk(m)) l = m+1;
            else r = m;
        }
        m = (l+r)/2;
        printf("%d\n", m);
    }
    return 0;
}
