#include <bits/stdc++.h>
using namespace std;

int t, n, k, r;

int main () {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &k, &n);
        int w[55], v[55], knap[1005];
        memset(w, 0, sizeof(w));
        memset(v, 0, sizeof(v));
        memset(knap, 0, sizeof(knap));
        for (int j = 0; j < n; j++)
            scanf("%d%d", &w[j], &v[j]);
        for (int x = 0; x < n; x++) {
            for (int y = 1005-1; y >= w[x]; y--) {
                knap[y] = max(knap[y], v[x]+knap[y-w[x]]);
            }
        }
        printf("Hey stupid robber, you can get %d.\n", knap[k]);
    }
    return 0;
}
