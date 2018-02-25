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

ld x, t, ans;
ll k, d;

int main () {
    scanf("%lld%lld%Lf", &k, &d, &t);
    if (k % d == 0) {
        ans = t;
    } else {
        x = k-(k%d)+d;
        ld eff = k + (x-k)/2.;
        ans = ((ll) (t/eff))*x;
        t -= ((ll) (t/eff))*eff;
        if (t + EPS < k) ans += t;
        else ans += k + 2*(t-k);
    }
    printf("%.10Lf\n", ans);
    return 0;
}
