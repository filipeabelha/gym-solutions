#include <bits/stdc++.h>
using namespace std;

int t, n, x;

int main () {
    scanf("%d", &t);
    while (t--) {
        int ans = -1;
        int num = 1e6;

        map <int, pair<int, int> > f;

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            f[x].first++;
            f[x].second = i;
        }

        for (auto p : f) {
            if (p.second.first > 1) continue;
            if (num > p.first) {
                num = p.first;
                ans = p.second.second;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
