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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll exp (ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = ans*b % MOD;
        b = b*b % MOD;
        e /= 2;
    }
    return ans;
}

ll f (ll x) {
    ll ans = 1;
    ans *= (exp(2, x)-1);
    ans *= exp(2, x-1);
    return ans;
}

int n;
set <ll> s;

int main () {
    for (int k = 1; k <= 20; k++) s.insert(f(k));
    scanf("%d", &n);
    for (int i = n; i >= 1; i--)
        if (n%i == 0 and s.count(i)) return 0*printf("%d\n", i);
    return 0;
}
