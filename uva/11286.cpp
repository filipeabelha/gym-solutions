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

int n, x;
map <vi, int> m;

int main () {
    while (~scanf("%d", &n) and n) {
        m.clear();
        int ans = 0;
        int mx = 0;
        while (n--) {
            vi v;
            int j = 5;
            while (j--) scanf("%d", &x), v.pb(x);
            sort(v.begin(), v.end());
            m[v]++;
            mx = max(mx, m[v]);
        }
        for (auto p : m) if (p.nd == mx) ans += p.nd;
        printf("%d\n", ans);
    }
    return 0;
}
