#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e7+10, MOD = 1300031;

ll fact[N], inv[N], p = MOD, tc, n, c;

int main () {
    inv[1] = 1;
    for (int i = 2; i < p; ++i)
        inv[i] = (p - (p/i)*inv[p%i]%p)%p;

    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = (i*fact[i-1])%MOD;

    scanf("%lld", &tc);
    while (tc--) {
        scanf("%lld%lld", &n, &c);
        ll num = fact[n-1+c];
        ll den = inv[(fact[n-1]*fact[c])%MOD];
        printf("%lld\n", (num*den)%MOD);
    }
    return 0;
}
