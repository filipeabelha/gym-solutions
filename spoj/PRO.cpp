#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

multiset <ll> s;

ll sum, x, n, r;
char chr;

int main () {
    scanf("%lld", &n);
    while (n--) {
        scanf("%lld", &r);
        while (r--) {
            scanf("%lld", &x);
            s.insert(x);
        }
        ll least = *s.begin();
        ll most = *(--s.end());
        sum += most - least;
        s.erase(s.begin()); s.erase((--s.end()));
    }
    printf("%lld\n", sum);
    return 0;
}
