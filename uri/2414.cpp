#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main () {
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        ans = max(ans, n);
    }
    printf("%d\n", ans);
    return 0;
}
