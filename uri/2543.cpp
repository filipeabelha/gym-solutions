#include <bits/stdc++.h>
using namespace std;

int n, id, ans, idx, x;

int main () {
    while(~scanf("%d%d", &n, &id)) {
        ans = 0;
        while (n--) {
            scanf("%d%d", &idx, &x);
            if (idx == id and !x) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
