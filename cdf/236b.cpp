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

const int INF = 0x3f3f3f3f, MOD = 1073741824, EPS = 1e-6, N = 1e3+10;

int cmp[N], a, b, c;
ll ans;
vi p;

void primes() {
    for (ll i = 2; i <= N; ++i) if (!cmp[i]) {
        for (ll j = i*i; j <= N; j+=i) cmp[j] = 1;
        p.pb(i);
    }
}

ll divi(int n) {
    ll ret = 1, expon = 1;
    for(int i = 0; p[i]*p[i] <= n; ++i) {
        while (n % p[i] == 0) expon++, n /= p[i];
        ret *= expon, expon = 1;
    }
    if (n > 1) ret *= 2;
    return ret;
}

int main () {
    primes();
    scanf("%d%d%d", &a, &b, &c);
    for (int i = 1; i <= a; i++) for (int j = 1; j <= b; j++) for (int k = 1; k <= c; k++)
        ans += divi(i*j*k) % MOD, ans %= MOD;
    printf("%lld\n", ans);
    return 0;
}
