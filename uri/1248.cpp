#include <bits/stdc++.h>

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        int dieta[100];
        int cheater = 0;
        memset(dieta, 0, sizeof(dieta));
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            dieta[chr]++;
        }
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            dieta[chr]--;
            if (dieta[chr] < 0)
                cheater = 1;
        }
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            dieta[chr]--;
            if (dieta[chr] < 0)
                cheater = 1;
        }
        if (cheater)
            printf("CHEATER\n");
        else {
            for (int j = 65; j <= 90; j++)
                if (dieta[j])
                    printf("%c", j);
            printf("\n");
        }
    }
    return 0;
}
