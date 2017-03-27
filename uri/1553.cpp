#include <bits/stdc++.h>

using namespace std;

int n, k, x, cnt;

int main () {
    while (1) {
        scanf("%d%d", &n, &k);
        if (!n and !k) break;
        cnt = 0;
        int faq[200];
        memset(faq, 0, sizeof(faq));
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            faq[x]++;
        }
        for (int i = 0; i <= 100; i++)
            if (faq[i] >= k) cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}
