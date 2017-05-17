#include <bits/stdc++.h>
using namespace std;

int n, x, mini, maxi, ans;

int main () {
    while (scanf("%d%d%d", &n, &mini, &maxi) != EOF) {
        ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            if (x >= mini and x <= maxi) ans++;
        }
        printf("%d\n", ans);
    }
}
