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
const ll P = 1e4;

ll v[N], a, sum, n;

ll cut (ll x) {
    ll ans = 0;
    for (int i = 0; i < n; i++) ans += max(v[i]-x, 0ll);
    return ans;
}

int main () {
    while (~scanf("%lld%lld", &n, &a) and n and a) {
        sum = 0;
        a *= P;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &v[i]);
            v[i] *= P;
            sum += v[i];
        }
        if (sum == a) {
            printf(":D\n");
            continue;
        } else if (sum < a) {
            printf("-.-\n");
            continue;
        }
        ll l = 1, m, r = 10000*P;
        while (l < r) {
            m = (l+r)/2;
            if (cut(m) > a) l = m+1;
            else r = m;
        }
        m = (l+r)/2;
        ll u = m-1;
        ll v = m+1;
        if (abs(cut(u)-a) < abs(cut(m)-a)) m = u;
        if (abs(cut(v)-a) < abs(cut(m)-a)) m = v;
        printf("%lld.%04lld\n", m/P, m%P);
    }
    return 0;
}
