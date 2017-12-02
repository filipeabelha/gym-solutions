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

pii dgt (ll x) {
    pii p = mp(0,0);
    while (x > 0) {
        p.st++;
        p.nd *= 10;
        p.nd += x % 10;
        x /= 10;
    }
    return p;
}

ll k, p, ans;

int main () {
    scanf("%lld%lld", &k, &p);
    for (ll i = 1; i <= k; i++) {
        ll s = i;
        pii pp = dgt(s);
        while (pp.st--) s *= 10;
        s += pp.nd;
        ans += s;
        ans %= p;
    }
    printf("%lld\n", ans);
    return 0;
}
