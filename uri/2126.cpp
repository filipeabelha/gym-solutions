#include <bits/stdc++.h>
using namespace std;

char n1[50], n2[50], chr;
int ans, pos;

int check (int ind) {
    for (int i = 0; i < strlen(n1); i++)
        if (n1[i] != n2[ind+i]) return 0;
    return 1;
}

int main () {
    for (int tc = 1; ; tc++) {
        ans = 0, pos = 0;
        if (scanf("%s%c%s%c", n1, &chr, n2, &chr) == EOF) break;
        for (int i = 0; i <= (strlen(n2)-strlen(n1)); i++)
            if (check(i)) ans++, pos = i;
        printf("Caso #%d:\n", tc);
        if (ans) {
            printf("Qtd.Subsequencias: %d\n", ans);
            printf("Pos: %d\n\n", ++pos);
        } else printf("Nao existe subsequencia\n\n");
    }
    return 0;
}
