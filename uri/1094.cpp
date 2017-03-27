#include <bits/stdc++.h>

int main () {
        int n, c = 0, r = 0, s = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                int num;
                char let;
                scanf("%d %c", &num, &let);
                if (let == 'C') c += num;
                if (let == 'R') r += num;
                if (let == 'S') s += num;
        };
        float pc = (100.000*c)/(c+r+s);
        float pr = (100.000*r)/(c+r+s);
        float ps = (100.000*s)/(c+r+s);
        printf("Total: %d cobaias\nTotal de coelhos: %d\nTotal de ratos: %d\nTotal de sapos: %d\nPercentual de coelhos: %.2f %%\nPercentual de ratos: %.2f %%\nPercentual de sapos: %.2f %%\n", c+r+s, c, r, s, pc, pr, ps);
        return 0;
}
