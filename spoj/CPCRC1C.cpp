#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, res, ans;

ll digsum (ll x) {
    if (x < 10) return x;
    return (x % 10) + digsum(x/10);
}

ll sum (ll x) {
    ll res = 0;
    ll xx = x;
    while (xx % 10 != 9) {
        if (xx == 0) return res;
        res += digsum(xx);
        xx--;
    }
    return res + ((x+1)/10)*45 + 10*sum((x+1)/10-1);
}

int main () {
    while (1) {
        scanf("%lld%lld", &a, &b);
        if (a == -1 and b == -1) break;
        if (a == 0 and b == 0) ans = 0;
        if (a == 0 and b > 0) ans = sum(b);
        if (a < 0 and b == 0) ans = sum(-a);
        if (a > 0 and b > 0) ans = sum(b) - sum(a-1);
        if (a < 0 and b < 0) ans = sum(-b) - sum(-a-1);
        if (a < 0 and b > 0) ans = sum(b) + sum(-a);
        printf("%lld\n", ans);
    }
    return 0;
}
