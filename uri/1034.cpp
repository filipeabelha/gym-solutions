#include <bits/stdc++.h>
using namespace std;

#define cl(x, v) memset((x), (v), sizeof(x))

const int N = 1e2;
const int A = 1e6+10;

int ans, n, amount, v[N], coin[A], tc;

int main () {
    scanf("%d", &tc);
    while (tc--) {
        cl(v, 0); cl(coin, 63);
        coin[0] = 0;
        scanf("%d", &n);
        scanf("%d", &amount);
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        for (int i = 0; i < n; i++)
            for (int j = v[i]; j < A; j++)
                coin[j] = min(coin[j], 1+coin[j-v[i]]);
        ans = coin[amount];
        printf("%d\n", ans);
    }
}
