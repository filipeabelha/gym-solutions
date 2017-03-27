#include <bits/stdc++.h>
using namespace std;

int tc, n, knap[50005], v[105];

int main () {
    scanf("%d", &tc);
    while(tc--) {
        int sum = 0;
        memset(knap, 0, sizeof(knap));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v[i]);
            sum += v[i];
        }
        int target = sum/2;
        for (int coin = 1; coin <= n; coin++)
            for (int amnt = target; amnt >= v[coin]; amnt--)
                knap[amnt] = max(knap[amnt], v[coin] + knap[amnt-v[coin]]);
        printf("%d\n", sum - 2*knap[target]);
    }
    return 0;
}
