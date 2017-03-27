#include <bits/stdc++.h>

int main () {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        char chr;
        scanf("%c", &chr);
        int pos = 1;
        while (1) {
            scanf("%c", &chr);
            if (chr == 'D') pos++;
            if (chr == 'E') pos--;
            if (chr == 10) break;
        }
        while (pos < 1) pos += 4;
        while (pos > 4) pos -= 4;
        if (pos == 1) printf("N\n");
        else if (pos == 2) printf("L\n");
        else if (pos == 3) printf("S\n");
        else if (pos == 4) printf("O\n");
    }
    return 0;
}
