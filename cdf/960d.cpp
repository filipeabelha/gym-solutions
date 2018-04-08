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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = (1ll << 60);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll lvl[N];

ll getlvl (ll x) {
    if (x <= 0) return 0;
    ll ans = 1;
    ll k = 1;
    while ((2*k) <= x) {
        k <<= 1;
        ans++;
    }
    return ans;
}

void add (ll l, ll k) {
    ll v = k;
    for (; l <= 60; l++) {
        lvl[l] += v;
        lvl[l] %= LMOD;
        v *= 2;
    }
}

ll q, t, x, k;

int main () {
    scanf("%lld", &q);
    while (q--) {
        scanf("%lld%lld", &t, &x);
        ll l = getlvl(x);
        if (t == 1) {
            scanf("%lld", &k);
            lvl[l] += k;
            lvl[l] %= LMOD;
        } else if (t == 2) {
            scanf("%lld", &k);
            add(l, k);
        } else if (t == 3) {
            ll re = x + lvl[l];
            re %= (1ll << l);
            while (getlvl(re) > l) re -= (1ll << (l-1));
            while (getlvl(re) < l) re += (1ll << (l-1));
            for (int i = l; i >= 1; i--) {
                x = re - lvl[i];
                x %= (1ll << i);
                while (getlvl(x) > i) x -= (1ll << (i-1));
                while (getlvl(x) < i) x += (1ll << (i-1));
                printf("%lld ", x);
                re /= 2;
            }
            printf("\n");
        }
    }

    return 0;
}
