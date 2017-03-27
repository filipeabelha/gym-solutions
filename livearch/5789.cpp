#include <bits/stdc++.h>

int s, b, l, r, pl, pr, esq[100005], dir[100005];

int main () {
    while (scanf("%d%d", &s, &b), s && b) {
        for (int i = 1; i <= s; i++) esq[i] = i-1, dir[i] = i+1;
        for (int i = 1; i <= b; i++) {
            scanf("%d%d", &l, &r);
            if (esq[l] == 0) printf("%c ", 42); else printf("%d ", esq[l]);
            if (dir[r] == s+1) printf("%c\n", 42); else printf("%d\n", dir[r]);
            dir[esq[l]] = dir[r];
            esq[dir[r]] = esq[l];
        }
        printf("-\n");
    }
    return 0;
}
