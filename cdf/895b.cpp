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

int n, x, k, v[N], u, z;
ll ans;
map <int, vi> iu, iz;
set <int> fqu, fqz;

int main () {
    scanf("%d%d%d", &n, &x, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        u = (v[i]-1)/x;  z = v[i]/x;
        iu[u].pb(v[i]);  iz[z].pb(v[i]);
        fqu.insert(u);   fqz.insert(z);
    }
    for (auto w : fqu) {
        int a = w+k;
        if (fqz.count(a)) {
            sort(iz[a].begin(), iz[a].end());
            for (auto s : iu[w]) {
                ans += iz[a].end()-lower_bound(iz[a].begin(), iz[a].end(), s);
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}
