#include <bits/stdc++.h>
using namespace std;

int v[60], n, start;

int go (int x) {
    if (v[x] == x) return x;
    else return go(v[x]);
}

int main () {
    while (1) {
        scanf("%d", &n); if (!n) break;
        for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
        scanf("%d", &start);
        printf("%d\n", go(start));
    }
    return 0;
}
