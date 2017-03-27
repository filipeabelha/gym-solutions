#include <bits/stdc++.h>

int sum, elem, n, found, ins, ans;

int main () {
    ins++;
    while (scanf("%d", &n) != EOF) {
        sum = 0, found = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &elem);
            if (found) continue;
            if (elem == sum) {
                found = 1;
                ans = elem;
                continue;
            }
            sum += elem;
        }
        printf("Instancia %d\n", ins);
        if (found) printf("%d\n\n", ans);
        else printf("nao achei\n\n");
        ins++;
    }
    return 0;
}
