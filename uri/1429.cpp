#include <bits/stdc++.h>
using namespace std;

int n, ans, fact;

int main () {
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        ans = 0; fact = 1;
        for (int i = 1; n > 0; i++) {
            fact *= i;
            ans += (n % 10)*fact;
            n /= 10;
        }
        printf("%d\n", ans);
    }
    return 0;
}
