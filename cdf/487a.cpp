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
const int N = 255;

ll ans = LINF;
ll a, b, c;

struct player {
    ll hp;
    ll atk;
    ll def;
} u, v;

bool play (player u, player v) {
    ll x = max(0ll, v.atk-u.def);
    ll y = max(0ll, u.atk-v.def);
    if (!y) return false;
    if (!x) return true;
    while (1) {
        u.hp -= x;
        v.hp -= y;
        if (u.hp > 0 and v.hp <= 0) return true;
        if (u.hp <= 0) return false;
    }
}

int main () {
    scanf("%lld%lld%lld", &u.hp, &u.atk, &u.def);
    scanf("%lld%lld%lld", &v.hp, &v.atk, &v.def);
    scanf("%lld%lld%lld", &a, &b, &c);

    for (ll j = 0; j < 205; j++) {
        for (ll k = 0; k < 105; k++) {
            player n = u;
            n.atk += j;
            n.def += k;

            ll l = 0, i, r = 1000005;
            while (l < r) {
                i = (l+r)/2;
                n.hp = u.hp + i;
                if (!play(n, v)) l = i+1;
                else r = i;
            }

            ll cost = l*a + j*b + k*c;

            ans = min(ans, cost);
        }
    }

    printf("%lld\n", ans);
    return 0;
}
