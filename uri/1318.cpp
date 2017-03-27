#include <bits/stdc++.h>

using namespace std;

int main () {
    while (1) {
        int x, y, k = 0;
        scanf("%d%d", &x, &y);
        if (x == 0 and y == 0) break;
        set <int> s;
        set <int> sk;
        for (int i = 0; i < y; i++) {
            int n;
            scanf("%d", &n);
            if (s.count(n) > 0 and sk.count(n) == 0) sk.insert(n), k++;
            s.insert(n);
        }
        printf("%d\n", k);
    }
    return 0;
}
