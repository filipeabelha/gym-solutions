#include <bits/stdc++.h>
using namespace std;

int t, n, x;

int main () {
    scanf("%d", &t);
    while (t--) {
        deque <int> v;
        map <int, int> qty;

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            qty[x] = 1;
            v.push_back(x);
        }

        if (n == 1) {
            printf("0\n");
            continue;
        }

        int a = v.front();
        int b = v.back();

        while (v.size() and v.front() == a) v.pop_front();
        if (v.empty()) {
            printf("0\n");
            continue;
        }
        while (v.size() and v.back() == b) v.pop_back();
        if (v.empty()) {
            printf("1\n");
            continue;
        }

        queue <int> q;

        while (v.size()) {
            int x = v.front(); v.pop_front();

            if (q.empty() or x != q.back()) {
                q.push(x);
                qty[x]++;
            }
        }

        int ans = 0x3f3f3f3f;
        for (auto p : qty) {
            ans = min(ans, p.second);
        }

        printf("%d\n", ans);
    }
    return 0;
}
