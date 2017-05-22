#include <bits/stdc++.h>
using namespace std;

#define cl(x, v) memset((x), (v), sizeof(x))

const int N = 1005;
int tc, n, t, p, ans, foodright[N], foodmax[N];

int main () {
    scanf("%d", &tc);
    while (tc--) {
        cl(foodright, 0);
        cl(foodmax, 0);
        ans = 0;
        scanf("%d", &n);
        while (n--) {
            scanf("%d%d", &t, &p);
            if (p >= 10 and p <= 100) foodright[t] = max(foodright[t], p);
            foodmax[t] = max(foodmax[t], p);
        }
        for (int i = 1; i <= 1000; i++) foodright[i] ? ans += foodright[i] : ans += foodmax[i];
        printf("%d\n", ans);
    }
    return 0;
}
