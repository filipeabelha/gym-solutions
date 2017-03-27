#include <bits/stdc++.h>

int n;
char chr;

int main () {
    scanf("%d", &n);
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        int letters[30];
        int maxx = 0;
        memset(letters, 0, sizeof(letters));
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            if (chr == 32) continue;
            if (chr >= 97 and chr <= 122) chr -= 32;
            if (chr >= 65 and chr <= 90) {
                letters[chr-65]++;
                if (letters[chr-65] > maxx)
                    maxx = letters[chr-65];
            }
        }
        for (int k = 0; k < 30; k++)
            if (letters[k] == maxx) printf("%c", k+97);
        printf("\n");
    }
    return 0;
}
