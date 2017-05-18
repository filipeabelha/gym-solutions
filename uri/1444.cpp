#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main () {
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        for (ans = 0; n > 1; ) {
            if (n % 3 == 0) ans += n/3, n = n/3;
            else ans += n/3 + 1, n = n/3 + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
