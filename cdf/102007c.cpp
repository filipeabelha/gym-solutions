#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;

const int N = 1e6+10;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll n, ans;

int main () {
    scanf("%d", &n);

    ans = LINF;
    for (ll i = 1; i*i <= n; i++) if (n % i == 0) {
        for (ll j = i; j*j <= n/i; j++) if ((n/i) % j == 0) {
            ll k = n/(i*j);
            ans = min(ans, 2*(i*j + i*k + j*k));
        }
    }
    printf("%lld\n", ans);

    return 0;
}
