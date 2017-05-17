#include <bits/stdc++.h>
using namespace std;

int n, q, x, v[30050];

int main () {
    while (scanf("%d%d", &n, &q) != EOF) {
        for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
        sort(v+1, v+n+1);
        for (int i = 1; i <= q; i++) {
            scanf("%d", &x);
            printf("%d\n", v[n-x+1]);
        }
    }
    return 0;
}
