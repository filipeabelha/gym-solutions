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
const int N = 1e6+5;

ll f (ll x) {
    ll ans = 1;
    while (x) {
        ll d = x%10;
        if (d) ans *= d;
        x /= 10;
    }
    return ans;
}

ll g (ll x) {
    if (x < 10) return x;
    return g(f(x));
}

ll cnt[N][15];
int q;

int main () {
    for (int x = 1; x < N; x++) {
        ll a = g(x);
        for (int i = 0; i <= 9; i++) cnt[x][i] = cnt[x-1][i];
        if (a >= 1 and a <= 10) cnt[x][a]++;
    }
    scanf("%d", &q);
    while (q--) {
        ll l, r, k;
        scanf("%lld%lld%lld", &l, &r, &k);
        printf("%lld\n", cnt[r][k] - cnt[l-1][k]);
    }
    return 0;
}
