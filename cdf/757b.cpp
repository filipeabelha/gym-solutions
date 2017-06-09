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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e5+10;

int cmp[N], m, x, cnt, ans = 1;
vi p, fact(N);

void primes() {
    for (ll i = 2; i <= N; ++i) if (!cmp[i]) {
        for (ll j = i*i; j <= N; j+=i) cmp[j] = 1;
        p.pb(i);
    }
}


void factorize(int n) {
    set <int> done;
    for(int i = 0; p[i]*p[i] <= n; ++i) {
        if (n % p[i]) continue;
        while (n % p[i] == 0) {
            n /= p[i];
            if (!done.count(p[i]))
                done.insert(p[i]), fact[p[i]]++, ans = max(ans, fact[p[i]]);
        }
    }
    if (n > 1 and !done.count(n)) done.insert(n), fact[n]++, ans = max(ans, fact[n]);
}

int main () {
    primes();
    scanf("%d", &m);
    while (m--) scanf("%d", &x), factorize(x);
    printf("%d\n", ans);
    return 0;
}
