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
const int N = 50;

string s;
ll x, q, f[N], inv[N];

ll fexp (ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % MOD;
        b = (b*b) % MOD;
        e >>= 1;
    }
    return ans;
}

ll bin (ll i, ll j) {
    ll ans = f[i];
    ans *= inv[j];        ans %= MOD;
    ans *= inv[abs(i-j)]; ans %= MOD;
    return ans;
}

int main () {
    f[0] = f[1] = 1;
    for (int i = 2; i < N; i++) f[i] = (i*f[i-1]) % MOD;
    for (int i = 0; i < N; i++) inv[i] = fexp(f[i], MOD-2);
    cin >> s;
    for (auto c : s) {
        if (c == '+') x++;
        if (c == '-') x--;
    }
    cin >> s;
    for (auto c : s) {
        if (c == '-') x++;
        if (c == '+') x--;
        if (c == '?') q++;
    }
    ll num = 0;
    for (ll i = 0; i <= q; i++)
        if (abs(2*i-q) == abs(x))
            num = bin(q, i);
    printf("%.10lf\n", (double) num/fexp(2, q));
    return 0;
}
