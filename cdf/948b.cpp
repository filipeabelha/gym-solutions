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
const int N = 1e6+10;

int cmp[N];
vector <ll> p;
ll n;
set <ll> fact;

void primes() {
    for (ll i = 2; i*i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j+=i) cmp[j]=1;
    }
    for (ll i = 2; i < N; i++) if (!cmp[i]) p.pb(i);
}

void getfact() {
    ll k = n;
    for (ll i = 0; p[i]*p[i] <= k; i++) {
        while (k % p[i] == 0) k /= p[i], fact.insert(p[i]);
    }
    if (k > 1) fact.insert(k);
}

bool slv (ll x) {
    for (auto y : p) {
        if (y >= x) break;
        ll s = x;
        if (x % y != 0) s += y-(x%y);
        for (auto f : fact) {
            if (f >= s) continue;
            ll ss = s;
            if (s % f != 0) ss += f-(ss%f);
            if (ss == n) return true;
        }
    }
    return false;
}


int main () {
    primes();
    scanf("%lld", &n);

    getfact();

    ll l = 3, m, r = n;
    while (l < r) {
        m = (l+r)/2;
        if (!slv(m)) l = m+1;
        else r = m;
    }
    printf("%lld\n", l);
    return 0;
}
