#include <bits/stdc++.h>
using namespace std;

#define cl(x, v) memset((x), (v), sizeof(x))

const int N = 2e3+10;
int tt[N], t, n, x, ans;

int main () {
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        cl(tt, 0); ans = 0;
        while (n--) {
            scanf("%d", &x);
            for (int i = 0; i < 10; i++) tt[x+i] = 1;
        }
        for (int i = 1; i < 1100; i++) if (tt[i]) ans++;
        printf("%d\n", ans);
    }
}
