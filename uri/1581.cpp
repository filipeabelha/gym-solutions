#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        int m, nobrk = 1;
        scanf("%d", &m);
        scanf("%c", &chr);
        char aprop[25];
        for (int j = 0; j < m; j++) {
            char ling[25];
            scanf("%s", ling);
            if (j > 0) 
                if (strcmp(ling, aprop) != 0)
                    nobrk = 0;
            strcpy(aprop, ling);

        }
        if (nobrk)
            printf("%s\n", aprop);
        else
            printf("ingles\n");
    }
    return 0;
}
