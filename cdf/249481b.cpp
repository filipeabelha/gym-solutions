#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f, n, x;
multiset <ll> m;

int main () {
    scanf("%lld%lld", &f, &n);
    while (n--) {
        scanf("%lld", &x);
        m.insert(x);
    }
    int ans = 0;
    while (1) {
        ll who = -1;
        for (auto x : m) if (x <= f) who = max(who, x);
        if (who == -1) break;
        m.erase(m.find(who));
        ans++;
        if (f <= (1LL << 60)) f <<= 1;
    }

    printf("%d\n", ans);

    return 0;
}
