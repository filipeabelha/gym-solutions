#include <bits/stdc++.h>
using namespace std;

int t, n, k, r;

int main () {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &n, &k);
        int w[105], knap[1005];
        memset(w, 0, sizeof(w));
        memset(knap, 0, sizeof(knap));
        for (int j = 0; j < n; j++) {
            scanf("%d", &r);
            int sum = 0, x;
            for (int p = 0; p < r; p++) {
                scanf("%d", &x);
                sum += x;
            }
            w[j] = sum;
        }
        for (int x = 0; x < n; x++) {
            for (int y = 1005-1; y >= w[x]; y--) {
                knap[y] = max(knap[y], w[x]+knap[y-w[x]]);
            }
        }
        printf("%d\n", knap[k]);
    }
    return 0;
}
