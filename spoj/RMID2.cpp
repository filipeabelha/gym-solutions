#include <bits/stdc++.h>
using namespace std;

typedef priority_queue <int> pq;

int n, tc;

int main () {
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        pq l, r;
        while (1) {
            scanf("%d", &n);
            if (!n) break;
            if (n == -1) {
                printf("%d\n", l.top());
                l.pop();
            } else if (l.empty() or n <= l.top())  l.push(n);
            else if (n > l.top())                  r.push(-n);

            while (l.size() > r.size()+1) r.push(-l.top()), l.pop();
            while (r.size() > l.size())   l.push(-r.top()), r.pop();
        }
    }
    return 0;
}
