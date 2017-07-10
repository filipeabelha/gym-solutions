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
const int N = 1e4+5;

int tc;
ll a, n, ans;
ll w[N], h[N], v[N];

int main () {
    scanf("%d", &tc);
    while (tc--) {
        cl(w, 0); cl(h, 0); cl(v, 0); ans = 0;
        scanf("%lld%lld", &a, &n);
        for (int i = 1; i <= n; i++) scanf("%lld", &w[i]);
        for (int i = 1; i <= n+1; i++) scanf("%lld", &h[i]);
        for (int i = 1; i <= n; i++) v[i] = max(v[i-1], h[i]);
        for (int i = n; i >= 1; i--) v[i] = min(v[i], max(v[i+1], h[i+1]));
        for (int i = 1; i <= n; i++) ans += v[i]*w[i]*a;
        printf("%lld\n", ans);
    }
    return 0;
}
