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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

ll fexp (ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % MOD;
        b = (b*b) % MOD;
        e >>= 1;
    }
    return ans;
}

ll f[N];
string s;

int main () {
    f[0] = f[1] = 1;
    for (ll i = 2; i < N; i++)
        f[i] = (i*f[i-1]) % MOD;

    while (cin >> s) {
        ll ans = f[s.size()];
        map <char, int> cnt;
        for (auto c : s) cnt[c]++;
        for (auto p : cnt) {
            ans *= fexp(f[p.nd], MOD-2);
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
