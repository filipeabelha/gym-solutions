#include <bits/stdc++.h>
using namespace std;

#define cl(x, v) memset((x), (v), sizeof(x))
typedef unsigned int ll;

int tc, m, d, ans, cntdir, cntkeys;
ll dir[25];

int main () {
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d", &m, &d);
        memset(dir, 0, sizeof(dir));
        ans = 50;

        for (int i = 0; i < d; i++) {
            int keys; scanf("%d", &keys);
            for (int p = 0; p < keys; p++) {
                int x; scanf("%d", &x);
                dir[i] |= (1 << x);
            }
        }

        for (ll i = 0; i < (1 << d); i++) {
            cntdir = 0;
            cntkeys = 0;
            ll sum = 0;
            int cnt = 0;
            for (int j = 0; j < 32; j++) {
                ll res = i & (1 << j);
                if (res > 0) sum |= dir[j], cntdir++;
            }
            for (int j = 0; j < 32; j++) {
                ll res = sum & (1 << j);
                if (res > 0) cntkeys++;
            }
            if (cntkeys >= m) ans = min(ans, cntdir);
        }

        if (ans == 50) printf("Desastre!\n");
        else printf("%d\n", ans);

    }
    return 0;
}
