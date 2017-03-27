#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll max (ll a, ll b) { return (a > b) ? a : b; }

char chr;
ll k, max_so_far, max_now, x;

int main () {
    while (1) {
        max_so_far = 0;
        max_now = 0;
        while (1) {
            x = scanf("%lld%c", &k, &chr);
            if (x == -1) break;
            max_now += k;
            max_now = max(0, max_now);
            max_so_far = max(max_so_far, max_now);
            if (chr == 10) break;
        }
        if (x == -1) break;
        printf("%lld\n", max_so_far);
    }
    return 0;
}
