#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, c;
int v[N];

int main () {
    int ans = 0;
    scanf("%d%d", &n, &c);

    int mx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        if (2*v[i] <= c) {
            ans++;
            mx = max(mx, v[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if ((2*v[i] > c) and (v[i] + mx <= c)) {
            ans++;
            break;
        }
    }

    if (n == 1 or ans == 0) ans = 1;

    printf("%d\n", ans);
    return 0;
}
