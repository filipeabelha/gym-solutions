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

ll n, s, f, a[N], v[N], maxi = -1, t = INF;

ll gett (ll s, int i) {
    ll ans = 1+s-i;
    if (ans > n) ans -= n;
    if (ans < 1) ans += n;
    return ans;
}

int main () {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    scanf("%lld%lld", &s, &f); f--;

    for (int i = 1; i <= n; i++)     v[i] = v[i-1]+a[i];
    for (int i = n+1; i <= 2*n; i++) v[i] = v[i-1]+a[i-n];

    for (int i = 1; i <= n; i++) {
        int sz = f-s+1;
        int r = i+sz-1;
        if (maxi == v[r]-v[i-1]) {
            t = min(t, gett(s, i));
        }
        if (maxi < v[r]-v[i-1]) {
            maxi = v[r]-v[i-1];
            t = gett(s, i);
        }
    }

    printf("%lld\n", t);

    return 0;
}
