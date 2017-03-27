#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        set <int> carn;
        for (int j = 0; j < x; j++) {
            int y;
            scanf("%d", &y);
            carn.insert(y);
        }
        printf("%d\n", (int) carn.size());
    }
    return 0;
}
