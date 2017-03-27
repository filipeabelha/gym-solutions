#include <bits/stdc++.h>
using namespace std;

#define cl(x, v) memset((x), (v), sizeof(x))

const int N = 110;

int n, st[N];

int main () {
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        for (int i = 1; 1; i++) {
            cl(st, 0);
            int m = i;
            int ind = 1;
            int cnt = m;
            int tot = 0;
            int brk = 0;

            while (1) {
                while (cnt < m) {
                    ind++;
                    if (ind > n) ind -= n;
                    if (!st[ind]) cnt++;
                }
                cnt = 0;
                st[ind] = 1;
                tot++;
                if (tot == n) {
                    if (ind == 13) brk = 1;
                    break;
                }
            }
            if (brk) {
                printf("%d\n", m);
                break;
            }
        }
    }
    return 0;
}
