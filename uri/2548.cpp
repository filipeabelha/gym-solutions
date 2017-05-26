#include <bits/stdc++.h>
using namespace std;

int a, b, x, ans;
priority_queue <int> pq;

int main () {
    while (~scanf("%d%d", &a, &b)) {
        for (int i = 0; i < a; i++) scanf("%d", &x), pq.push(x);
        while (b--) ans += pq.top(), pq.pop();
        while (!pq.empty()) pq.pop();
        printf("%d\n", ans); ans = 0;
    }
    return 0;
}
